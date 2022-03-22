 "All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim


" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif

"desabilitar mouse
set mouse= 

"desabilitar backups
set nobackup
set noswapfile
set nowritebackup


"clipboard do sistema
"set clipboard=unnamed
set clipboard=unnamedplus

"tabs por espaços
set expandtab
set shiftwidth=4
set tabstop=4
set smarttab

"identação
filetype plugin indent on
set autoindent
set smartindent

"Régua, quebra e número de linhas
set number
"set ruler

"busca
set hlsearch
set ignorecase
set incsearch

"Fonte e janela
set guifont=consolas:h10
set encoding=utf-8

set relativenumber

execute pathogen#infect()

filetype on
syntax enable
syntax on
"set t_Co=256
"let g:solarized_termcolors=256
"set background=dark
colorscheme molokai


let g:comfortable_motion_scroll_down_key = "j"
let g:comfortable_motion_scroll_up_key = "k"

"autocmd vimenter * ++nested colorscheme gruvbox

set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

"fix matchpar
set showmatch                  " Briefly jump to a paren once it's balanced
set matchpairs+=\<:\>
" With `Cursor guibg=fg guifg=bg` + default MatchParen styling, it makes the
" cursor seem like it has actually jumped to the patching pair. This instead
" makes the MatchParen style preserve the background color, so that the
" Cursor can flip it appropriately.
hi! MatchParen cterm=NONE,bold gui=NONE,bold guibg=bg guifg=lightblue ctermbg=bg ctermfg=lightblue

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
"let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
            
inoremap {<CR> {<CR>}<C-O>O
inoremap jk <ESC>
inoremap JK <ESC>
nnoremap t 0i//<ESC>$
nnoremap T 0xx$
nnoremap <C-Left> :tabprevious<CR>
nnoremap <C-Right> :tabnext<CR>
nnoremap <TAB> :NERDTreeToggle<CR>
nmap <silent> <C-C> :silent noh<CR>
nnoremap <C-A> ggVG

autocmd filetype cpp nnoremap <F5> :w <bar> !comp %:r && ./%:r <CR>
autocmd filetype cpp nnoremap <F6> :w <bar> !comp %:r && ./%:r < in1.txt<CR>
