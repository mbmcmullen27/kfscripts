#include <stdio.h>
#include <curl/curl.h>
 
int fetch(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "192.168.1.77/app/blinky");
    
    FILE *f = fopen("nul", "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    // printf("response %u\n", res);


    curl_easy_cleanup(curl);
    return response_code;
  }
  return 0;
}
