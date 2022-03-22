#ifdef EBUG
#include <sys/resource.h>
#endif

int main() {
#ifdef EBUG
    const rlim_t kStackSize = 100 * 1024 * 1024;   // min stack size = 100 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
#endif

}
