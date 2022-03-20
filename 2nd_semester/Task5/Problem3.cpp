#include <iostream>
#include <regex>
#include <iomanip>

int main()
{
    std::string text = "first@mail.ru Text for test asdkjj@lkjdsa qq@adsl.adsk_.ru email@example.ru qq@qq. "
        " lalala wrong@sad@dsa.sda asa gOOd@dom-ain.Org, write to qq@my-mail.com! qq@.qq"
        " wr@mail.r1u correct@qqq.cd_om li@st.of,correct_emails@gmail.com,another-one@yandex.ru."
        " _qwe@qwe.qwe qwe-@qwe.qwe e-l_sd.ad@d.sd.sf-d.a_sa.qe q@q.q q@q.qqqqqqqqqq q@q_.qq";

    std::regex pattern(
        R"((?:[\s,]|^))"                                          // separating characters
        R"(([[:alpha:]](?:[[:alpha:]_\.-]*[[:alpha:]])?)"         // username
        R"(@)"                                                    // @
        R"(((?:[[:alpha:]](?:[[:alpha:]_\.-]*[[:alpha:]])?\.)+)"  // domain name
            R"((?:[[:alpha:]][[:alpha:]_-]{0,7}[[:alpha:]]))))"       // TLD
        R"((?=[\s,.!?]|$))"                                       // separating characters
    );

    std::sregex_iterator begin(text.cbegin(), text.cend(), pattern);
    std::sregex_iterator end;

    std::for_each(begin, end, [](const std::smatch& m)
        {
            std::cout << std::left << std::setw(30) << m[1] << m[2] << std::endl;
        });

    return EXIT_SUCCESS;
}