class GetRequest {
private:
    const std::string URL_;
public:
    explicit GetRequest(const char *URL);

    std::string getJson() const;

    ~GetRequest();

    static size_t WriteMemoryCallback(void *contents, size_t size, size_t memcp, void *userp);

};


