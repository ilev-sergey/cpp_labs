#include <iostream>
#include <regex>
#include <iomanip>

int main()
{
    std::string text = "first@mail.ru Text for test asdkj$j@lkjdsa $^@adsl.adsk_.ru email@example.ru q@q. "
        " lalala wrong@sad#@dsa.sda asa gOOd@dom-ain.Org, write to q&'#%@my-mail.com! q@.q"
        " wr@mail.r1u wrong@qqq.cd_om li@st.of,correct_emails@gmail.com,another-one+3@yandex.ru";

    std::regex pattern(R"((?:[\s,]|^)([\w!#$%&'*+/=?^_‘{|}~-]+@([-[:alnum:]]+\.[[:alpha:]]+))(?=[\s,.!?]|$))");

    std::sregex_iterator begin(text.cbegin(), text.cend(), pattern);
    std::sregex_iterator end;

    std::for_each(begin, end, [](const std::smatch& m)
        {
            std::cout << std::left << std::setw(30) << m[1] << m[2] << std::endl;
        });

    return EXIT_SUCCESS;
}