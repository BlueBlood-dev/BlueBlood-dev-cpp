#include "GetRequest.h"

GetRequest::GetRequest(const char *URL) : URL_(URL) {
    curl_global_init(CURL_GLOBAL_ALL);
}

GetRequest::~GetRequest() {
    curl_global_cleanup();
}

size_t GetRequest::WriteMemoryCallback(void *contents, size_t size, size_t memcp, void *userp) {
    ((std::string *) userp)->append(static_cast<char *>(contents), size * memcp);
    return size * memcp;
}

std::string GetRequest::getJson() const{
    std::string response;
    CURL *curlHandle = curl_easy_init();
    curl_easy_setopt(curlHandle, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curlHandle, CURLOPT_URL, URL_.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curlHandle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    if (curl_easy_perform(curlHandle) != CURLE_OK)
        throw std::invalid_argument("Wrong curl_response_code\n");

    return response;
}