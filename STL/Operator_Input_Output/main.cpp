#include <iostream>
#include <string>

using namespace std;

class OperatorInputOutput{
public:
    OperatorInputOutput(const string& rhs):str_(rhs){}

    OperatorInputOutput(const OperatorInputOutput& rhs)
    {
        str_ = rhs.str_;
    }

    OperatorInputOutput& operator = (const OperatorInputOutput& rhs)
    {
        str_ = rhs.str_;

        return *this;
    }

    friend istream& operator >> (istream &in, OperatorInputOutput &rhs);

    friend ostream& operator << (ostream &out, const OperatorInputOutput &rhs);

private:
    string str_;
};

istream& operator >> (istream &in, OperatorInputOutput &rhs)
{
    if(in)
    {
        in >> rhs.str_;
    }
    else
    {
        cout << "input error" << endl;
    }

    return in;
}

ostream& operator << (ostream &out, const OperatorInputOutput &rhs)
{
    out << rhs.str_;

    return out;
}

int main()
{
    OperatorInputOutput op( string("linzhenhua") );

    cout << op;

    cout << endl;

    cin >> op;

    cout << op;

    return 0;
}
