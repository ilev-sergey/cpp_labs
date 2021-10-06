class Class
{
private:
    int date1;
protected:
    int date2;
    friend f1(); // access to date1, date2
};

class ChildClass : private
{
    // private date2
private:
    int date3;
    friend f2(); // access to date2, date3
}

// date1 is available for f1
// date2 is available for f1, f2
// date3 is available for f2