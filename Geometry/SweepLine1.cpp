#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair

#define ll long long

using namespace std;

struct event {
    int x, y, flag;

    bool operator<(const event &b) const{
        return x < b.x;
    }
};

int main() {
    int n;
    cin >> n;

    vector<event> events;

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        event p1 = {x1,y1,1};
        event p2 = {x2,y2,0};

        events.PB(p1);
        events.PB(p2);
    }

    sort(events.begin(), events.end());
    multiset<int> alturas;
    event last_event = {0,0,0};
    ll ans = 0;
    for(int i = 0; i < events.size(); i++) {
        event ev = events[i];
        if(ev.flag == 1) { //in
            if(alturas.size() > 0) 
                ans += (*(--alturas.end()) * (ev.x - last_event.x));
            alturas.insert(ev.y);
        }else { //out
            if(alturas.size() > 0)
                ans += (*(--alturas.end()) * (ev.x - last_event.x));
            alturas.erase(alturas.find(ev.y));
        }
        last_event = ev;
    }
    cout << ans << endl;
}
