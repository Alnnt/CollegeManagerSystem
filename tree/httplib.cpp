#include "httplib.h"
#include "auth.h"

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

//#define CPPHTTPLIB_OPENSSL_SUPPORT 0

string HttpGet(string body) {
    //body = "/cms.php?account=account&password=123456&type=reg&email=1138745158@qq.com&CheckCode=GHTJ3"
    httplib::Client cli("www.wm-valley.com", 80); //"www.wm-valley.com
    if (auto res = cli.Get(body)) {
        //cout << res->status << endl;
        //cout << res->get_header_value("Content-Type") << endl;
        //cout << res->body << endl;
        return res->body;
    }
    else {
        cout << "error code: " << res.error() << std::endl;
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
        auto result = cli.get_openssl_verify_result();
        if (result) {
            cout << "verify error: " << X509_verify_cert_error_string(result) << endl;
        }
#endif
    }
}