int download(char *url, char *outfilename) {
  // 0 = success, 1 = failure
  CURL *curl;
  FILE *fp;
  CURLcode res;
  curl = curl_easy_init();
  if (curl) {
    fp = fopen(outfilename, "w");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
  }
  return 0;
}
