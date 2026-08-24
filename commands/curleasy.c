#include <stdio.h>
#include <curl/curl.h>
#include "curleasy.h"

int download(char *url, char *outfilename) {
  // 0 = success, 1 = failure
  CURL *curl;
  FILE *fp;
  CURLcode res;
  curl = curl_easy_init();
  if (curl) {
    fp = fopen(outfilename, "w");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(res));
      return 1;
    }
    curl_easy_cleanup(curl);
    fclose(fp);
  }
  return 0;
}
