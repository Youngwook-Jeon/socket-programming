// 도메인 이름과 IP의 상호 변환
#include "../Common.h"

#define TESTNAME "www.google.com"

// 도메인 이름 -> IPv4
bool GetIPAddr(const char *name, struct in_addr *addr)
{
    struct hostent *ptr = gethostbyname(name);
    if (ptr == NULL) {
        err_display("gethostbyname()");
        return false;
    }

    if (ptr->h_addrtype != AF_INET) return false;
    memcpy(addr, ptr->h_addr, ptr->h_length);
    return true;
}

bool GetDomainName(struct in_addr addr, char *name, int namelen)
{
    struct hostent *ptr = gethostbyaddr((const char *)&addr, sizeof(addr), AF_INET);
    if (ptr == NULL) {
        err_display("gethostbyaddr()");
        return false;
    }

    if (ptr->h_addrtype != AF_INET) return false;
    strncpy(name, ptr->h_name, namelen);
    return true;
}

int main(int argc, char *argv[])
{
    printf("도메인 이름 변환전: %s\n", TESTNAME);

    // 도메인 이름 -> 아이피주소
    struct in_addr addr;
    if (GetIPAddr(TESTNAME, &addr)) {
        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr, str, sizeof(str));
        printf("IP 주소 변환후: %s\n", str);

        // 아이피주소 -> 도메인 이름
        char name[256];
        if (GetDomainName(addr, name, sizeof(name))) {
            printf("도메인 이름 변환후: %s\n", name);
        }
    }

    return 0;
}