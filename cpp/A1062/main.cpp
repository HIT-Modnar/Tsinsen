// Source : http://www.tsinsen.com/A1062
// Author : Modnar
// Date   : 2019-03-13

/********************************************************************************
 *
 *   Speed of rabbit is 'v1' and turtle's is 'v2'. Once rabbit is ahead of turtle 
 * distance of 't', the rabbit would sleep 's' seconds. If the rabbit sleep after
 * s seconds and the rabbit is still ahead of the turtle t or more distance, the
 * rabbit will choose running rather than sleeping.
 *
 *******************************************************************************/ 

#include <iostream>

int main(int argc, char *argv[]) {
    int v1, v2, t, s, l, len_rabbit = 0;
    std::cin >> v1 >> v2 >> t >> s >> l;
    int turtle_time = l / v2, rabbit_time = 0;
    // Mark whether the rabbit is eager to sleep.
    bool eager_to_sleep = true; 
    while (rabbit_time < turtle_time) {
        if ((len_rabbit >= v2 * rabbit_time + t) && eager_to_sleep) {
            rabbit_time += s;
            // Once the rabbit has woke up, the rabbit won't want to sleep before
            // next running.
            eager_to_sleep = false;
            continue;
        }
        len_rabbit += v1;
        ++rabbit_time;
        if (len_rabbit >= l) break;
        eager_to_sleep = true;
    }
    char ans;
    if (len_rabbit >= l && rabbit_time < turtle_time) ans = 'R';
    else if (len_rabbit < l || rabbit_time > turtle_time) ans = 'T';
    else ans = 'D';
    std::cout << ans << std::endl 
              << (rabbit_time < turtle_time ? rabbit_time : turtle_time) << std::endl;
    return 0;
}
