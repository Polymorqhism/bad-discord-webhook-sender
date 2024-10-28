#include<curl/curl.h>
#include<iostream>

void post(const char *URL, const char *data) {
  CURL *curl = curl_easy_init();
  CURLcode res;

  struct curl_slist *headers = NULL;

  if(curl) {
    std::cout << "curl init done" << std::endl;
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  } 
}

int main() {
  std::string URL;
  std::string content;
  curl_global_init(CURL_GLOBAL_ALL);
  std::cout << "Enter URL: ";
  std::getline(std::cin, URL);  

  while(true) {
    std::cout << "Enter content: ";
    std::getline(std::cin, content);

    const std::string data = "{\"content\": \"" + content +"\"}";
    post(URL.c_str(), data.c_str());
  }
  curl_global_cleanup();
}
