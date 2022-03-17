#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

#include <boost/locale.hpp>

#include <Windows.h>

std::string convert_locale_to_utf(const std::string& string)
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);

    std::locale locale =
        generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::to_utf < char >(string, locale);
}

std::string convert_utf_to_locale(const std::string& string)
{
    boost::locale::generator generator;
    generator.locale_cache_enabled(true);

    std::locale locale =
        generator(boost::locale::util::get_system_locale());

    return boost::locale::conv::from_utf < char >(string, locale);
}

int main()
{
    system("chcp 1251");

    std::string text = "Аэрофотосъёмка ландшафта уже выявила земли богачей и процветающих крестьян.";

    std::unordered_map < char32_t, std::u32string > transliteration_set =
    {
        {U'а', U"a"},  {U'б', U"b"},   {U'в', U"v"},  {U'г', U"g"}, {U'д', U"d"},
        {U'е', U"e"},  {U'ё', U"jo"},  {U'ж', U"zh"}, {U'з', U"z"}, {U'и', U"i"},
        {U'й', U"j"},  {U'к', U"k"},   {U'л', U"l"},  {U'м', U"m"}, {U'н', U"n"},
        {U'о', U"o"},  {U'п', U"p"},   {U'р', U"r"},  {U'с', U"s"}, {U'т', U"t"},
        {U'у', U"u"},  {U'ф', U"f"},   {U'х', U"h"},  {U'ц', U"c"}, {U'ч', U"ch"},
        {U'ш', U"sh"}, {U'щ', U"shh"}, {U'ъ', U"#"},  {U'ы', U"y"}, {U'ь', U"'"},
        {U'э', U"je"}, {U'ю', U"j"},   {U'я', U"ja"},

        {U'А', U"A"},  {U'Б', U"B"},   {U'В', U"V"},  {U'Г', U"G"}, {U'Д', U"D"},
        {U'Е', U"E"},  {U'Ё', U"Jo"},  {U'Ж', U"Zh"}, {U'З', U"Z"}, {U'И', U"I"},
        {U'Й', U"J"},  {U'К', U"K"},   {U'Л', U"L"},  {U'М', U"M"}, {U'Н', U"N"},
        {U'О', U"O"},  {U'П', U"P"},   {U'Р', U"R"},  {U'С', U"S"}, {U'Т', U"T"},
        {U'У', U"U"},  {U'Ф', U"F"},   {U'Х', U"H"},  {U'Ц', U"C"}, {U'Ч', U"Ch"},
        {U'Ш', U"Sh"}, {U'Щ', U"Shh"}, {U'Ъ', U"#"},  {U'Ы', U"Y"}, {U'Ь', U"'"},
        {U'Э', U"Je"}, {U'Ю', U"J"},   {U'Я', U"Ja"}
    };

    std::string u8text = convert_locale_to_utf(text); // convert to UTF8
    std::u32string u32text = boost::locale::conv::utf_to_utf<char32_t, char>(u8text); // convert to UTF32

    std::u32string u32output;
    std::for_each(std::begin(u32text), std::end(u32text), [&transliteration_set, &u32output](auto x) // transliteration
        {
            if (transliteration_set.contains(x))
            {
                u32output += transliteration_set[x];
            }
            else
            {
                u32output += x;
            }
        });

    u8text = boost::locale::conv::utf_to_utf < char, char32_t >(u32output); // convert to UTF8
    text = convert_utf_to_locale(u8text); // convert to system_locale

    std::cout << text << std::endl;

    return 0;
}