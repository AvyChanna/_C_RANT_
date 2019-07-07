#ifndef _C_RANT_CONSTANTS_H_
#define _C_RANT_CONSTANTS_H_

const char *	API					= "https://www.devrant.com/api";
const int 		APP_VERSION			= 3;

const char *	COLLABS_PATH		= "%s/devrant/collabs?app=%d&sort=%s&limit=%d&skip=%d";
const char *	RANTS_PATH			= "%s/devrant/rants?&app=%dsort=%s&range=%s&limit=%d&skip=%d";
const char *	RANT_PATH			= "%s/devrant/rants/%d?app=%d";
const char *	SURPRISE_PATH		= "%s/devrant/rants/surprise?app=%d";
const char *	SEARCH_PATH			= "%s/devrant/search?app=%d&term=%s";
const char *	STORY_RANTS_PATH	= "%s/devrant/story-rants?&app=%dsort=%s&range=%s&limit=%d&skip=%d" ;
const char *	SUPPORTERS_PATH		= "%s/devrant/supporters?app=%d";
const char *	WEEKLY_LIST_PATH	= "%s/devrant/weekly-list?app=%d";
const char *	WEEKLY_RANTS_PATH	= "%s/devrant/weekly-rants?app=%d&week=%d&sort=%s&limit=%d&skip=%d";
const char *	USER_ID_PATH		= "%s/get-user-id?app=%d&username=%s";
const char *	USER_PATH			= "%s/users/%d?app=%d&content=%s&skip=%d";

const char *	_SORT_BY_ALGO_		= "algo";
const char *	_SORT_BY_TOP_		= "top";
const char *	_SORT_BY_RECENT_	= "recent";

const char *	_RANGE_DAY_			= "day";
const char *	_RANGE_WEEK_		= "week";
const char *	_RANGE_MONTH_		= "month";
const char *	_RANGE_ALL_			= "all";

const char *	_CONTENT_ALL_		= "all";
const char *	_CONTENT_RANTS_		= "rants";
const char *	_CONTENT_UPVOTED_	= "upvoted";
const char *	_CONTENT_COMMENTS_	= "comments";
const char *	_CONTENT_VIEWED_	= "viewed";
const char *	_CONTENT_FAVORITES_	= "favorites";
const char *	_CONTENT_COLLABS_	= "collabs";

typedef enum{
	SORT_BY_ALGO,
	SORT_BY_TOP,
	SORT_BY_RECENT
}SORT;

typedef enum{
	RANGE_DAY,
	RANGE_WEEK,
	RANGE_MONTH,
	RANGE_ALL
}RANGE;

typedef enum CONTENT{
	CONTENT_ALL,
	CONTENT_RANTS,
	CONTENT_UPVOTED,
	CONTENT_COMMENTS,
	CONTENT_VIEWED,
	CONTENT_FAVORITES,
	CONTENT_COLLABS
}CONTENT;

const char* get_sort_enum(SORT s){
	if(s == SORT_BY_RECENT)
		return _SORT_BY_RECENT_;
	else if(s == SORT_BY_TOP)
		return "top";
	return "algo";
}

const char* get_range_enum(RANGE r){
	if(r == RANGE_MONTH)
		return _RANGE_MONTH_;
	else if(r == RANGE_WEEK)
		return _RANGE_WEEK_;
	else if(r == RANGE_DAY)
		return _RANGE_DAY_;
	return _RANGE_ALL_;
}

const char* get_content_enum(CONTENT c){
	if(c == CONTENT_RANTS)
	return _CONTENT_RANTS_;
	else if(c == CONTENT_UPVOTED)
		return _CONTENT_UPVOTED_;
	else if(c == CONTENT_COMMENTS)
		return _CONTENT_COMMENTS_;
	else if(c == CONTENT_VIEWED)
		return _CONTENT_VIEWED_;
	else if(c == CONTENT_FAVORITES)
		return _CONTENT_FAVORITES_;
	else if(c == CONTENT_COLLABS)
		return _CONTENT_COLLABS_;
	return _CONTENT_ALL_;
}
#endif // _C_RANT_CONSTANTS_H_
