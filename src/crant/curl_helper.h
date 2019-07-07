#ifndef _C_RANT_CURL_HELPER_
#define _C_RANT_CURL_HELPER_
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>

typedef struct{
	char* memory;
	size_t size;
}MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp){
	// Find real size to append.
	size_t realsize = size * nmemb;
	MemoryStruct* mem = (MemoryStruct*)userp;

	// Realloc our data structure to make room for new data.
	char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
	// If there was a problem in realloc, then return 0.
	// If return value != realsize, libcurl understands that something
	// might have gone wrong.
	if(ptr == NULL)
		return 0;

	// Now that we have space, we can append our new data.
	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	// Return value == realsize tells it is okay to continue.
	return realsize;
}

CURLcode GET_url(char url[], char** buffer){
	// Return code for curl.
	CURLcode ret;
	// Handle for curl
	CURL *hnd;
	// Data Structure to hold our downloaded string
	MemoryStruct ds;
	ds.memory = (char*)malloc(1);
	ds.size = 0;
	// It is advised to add the below line before the program start
	// It basically sets the whole curl environment
	// Required only once per program, can call more than once but
	// won't do anything.

	// CAUTION: it is NOT thread safe. So, if you want to
	// use pthread, use global init BEFORE  creating any threads

	//  curl_global_init(CURL_GLOBAL_ALL);

	// This handle will download a URL
	hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
	// URL to GET
	curl_easy_setopt(hnd, CURLOPT_URL, url);
	// Do not show progress bar
	curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
	// send all data to this function
	curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
	// we pass our 'ds' struct to the callback function
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, (void*)&ds);
	// User Agent, Follow redirects
	curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.58.0");
	curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
	curl_easy_setopt(hnd, CURLOPT_FOLLOWLOCATION, 1);
	//   curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
	// Actual GET happens here
	ret = curl_easy_perform(hnd);

	// check for errors
	if(ret == CURLE_OK){
		// if(sizeof(*buffer)!=0)
		// 	free(*buffer);
		*buffer = ds.memory;
	} else free(ds.memory);

	// Cleanup
	curl_easy_cleanup(hnd);
	hnd = NULL;

	// USe this when program is about to end.
	// Required once, can be used multiple times
	// curl_global_cleanup();
  return ret;
}

#endif // _C_RANT_CURL_HELPER_
