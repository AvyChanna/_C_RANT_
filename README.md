# _C_Rant_

A devRant API wrapper for C.

## Using _C_Rant_

```C
#include<curl/curl.h>
#include<crant/all.h>
int main()
{
    // Start with init'ing curl

    curl_global_init(CURL_GLOBAL_ALL);


    // List of endpoints currently covered

    char* s0  = get_collabs(SORT_BY_ALGO, 0, 0);
    char* s1  = get_rants(SORT_BY_ALGO, RANGE_ALL, 1, 0);
    char* s2  = get_rant(226724);
    char* s3  = get_surprise();
    char* s4  = search_rant("fuck off");
    char* s6  = get_story_rants(SORT_BY_ALGO, RANGE_ALL, 1, 0);
    char* s7  = get_supporters();
    char* s8  = get_weekly_list();
    char* s9  = get_weekly_rants(128, SORT_BY_ALGO, 1, 0);
    char* s10 = get_user_id("AvyChanna");
    char* s11 = get_user_info(714135, CONTENT_ALL, 0);

    // End with curl cleanup

    curl_global_cleanup();
    return 0;
}
```

## TODO

-[] Add docs
-[] Add data validation
-[] Add JSON parsing
-[] Add auth endpoints and things like vote favourite subscribe and post
