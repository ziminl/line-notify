#include <iostream>
#include <string>
#include <curl/curl.h>

void sendLineNotify(const std::string& token, const std::string& message) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + token).c_str());
        
        const char* url = "https://notify-api.line.me/api/notify";
        std::string payload = "message=" + message;
        
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl failed or error: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "sent" << std::endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
}

int main() {
    std::string token = "YOUR_ACCESS_TOKEN";
    std::string message = "testtesttest!";

    sendLineNotify(token, message);

    return 0;
}
