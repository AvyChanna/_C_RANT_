#ifndef _C_RANT_ENDPOINTS_
#define _C_RANT_ENDPOINTS_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include"crant/curl_helper.h"
#include"crant/constants.h"

#define BUFFER_LEN 100

char* get_collabs(SORT s, int limit, int skip){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, COLLABS_PATH, API, APP_VERSION, get_sort_enum(s), limit, skip);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, len, COLLABS_PATH, API, APP_VERSION, get_sort_enum(s), limit, skip);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_rants(SORT s, RANGE r, int limit, int skip){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr,BUFFER_LEN, RANTS_PATH, API, APP_VERSION, get_sort_enum(s), get_range_enum(r), limit, skip);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr,BUFFER_LEN, RANTS_PATH, API, APP_VERSION, get_sort_enum(s), get_range_enum(r), limit, skip);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_rant(int rant_id){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr,BUFFER_LEN, RANT_PATH, API, rant_id, APP_VERSION);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr,BUFFER_LEN, RANT_PATH, API, rant_id, APP_VERSION);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_surprise(){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr,BUFFER_LEN, SURPRISE_PATH, API, APP_VERSION);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr,BUFFER_LEN, SURPRISE_PATH, API, APP_VERSION);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* search_rant(const char* search_term){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr,BUFFER_LEN, SEARCH_PATH, API, APP_VERSION, search_term);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr,BUFFER_LEN, SEARCH_PATH, API, APP_VERSION, search_term);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_story_rants(SORT s, RANGE r, int limit, int skip){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, STORY_RANTS_PATH, API, APP_VERSION, get_sort_enum(s), get_range_enum(r), limit, skip);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, STORY_RANTS_PATH, API, APP_VERSION, get_sort_enum(s), get_range_enum(r), limit, skip);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_supporters(){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, SUPPORTERS_PATH, API, APP_VERSION);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, SUPPORTERS_PATH, API, APP_VERSION);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_weekly_list(){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, WEEKLY_LIST_PATH, API, APP_VERSION);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, WEEKLY_LIST_PATH, API, APP_VERSION);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_weekly_rants(int week_no, SORT s, int limit, int skip){
		char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, WEEKLY_RANTS_PATH, API, APP_VERSION, week_no, get_sort_enum(s), limit, skip);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, WEEKLY_RANTS_PATH, API, APP_VERSION, week_no, get_sort_enum(s), limit, skip);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_user_id(const char* user_name){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, USER_ID_PATH, API, APP_VERSION, user_name);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, USER_ID_PATH, API, APP_VERSION, user_name);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
char* get_user_info(int user_id, CONTENT c, int skip){
	char* buffer_ptr = (char*)malloc(BUFFER_LEN*sizeof(char));
	int len = snprintf(buffer_ptr, BUFFER_LEN, USER_PATH, API, user_id, APP_VERSION, get_content_enum(c), skip);
	if(len > BUFFER_LEN){
		free(buffer_ptr);
		buffer_ptr = (char*)malloc(len*sizeof(char));
		snprintf(buffer_ptr, BUFFER_LEN, USER_PATH, API, user_id, APP_VERSION, get_content_enum(c), skip);
	}
	char *return_buffer;
	GET_url(buffer_ptr, &return_buffer);
	return return_buffer;
}
int main()
{
	// TODO - Make docs
	// TODO - Add data validation
	printf("COLLABS-\n%s\n\n", get_collabs(SORT_BY_ALGO, 0, 0));
	// printf("RANTS-\n%s\n\n", get_rants(SORT_BY_ALGO, RANGE_ALL, 1, 0));
	// printf("RANT2168836-%s\n\n", get_rant(2168836));
	// printf("SURPRISE-\n%s\n\n", get_surprise());
	// printf("SEARCH \"fuch-off\"-\n%s\n\n", search_rant("fuck off"));
	// printf("STORY-\n%s\n\n", get_story_rants(SORT_BY_ALGO, RANGE_ALL, 1, 0));
	// printf("Supporters-%s\n\n", get_supporters());
	// printf("WEEKLY LIST-\n%s\n\n", get_weekly_list());
	// printf("WEEKLY RANTS-\n%s\n\n", get_weekly_rants(128, SORT_BY_ALGO, 1, 0));
	// printf("USER ID-\n%s\n\n", get_user_id("AvyChanna"));
	// printf("USER INFO-\n%s\n\n", get_user_info(714135, CONTENT_ALL, 0));
	return 0;
}

#endif // _C_RANT_ENDPOINTS_
