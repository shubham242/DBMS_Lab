#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> prices;

void initPrices()
{
    prices.insert(pair<char, int>('A', 50));
    prices.insert(pair<char, int>('B', 100));
    prices.insert(pair<char, int>('C', 150));
    prices.insert(pair<char, int>('D', 200));
    prices.insert(pair<char, int>('E', 250));
    prices.insert(pair<char, int>('F', 300));
    prices.insert(pair<char, int>('G', 350));
    prices.insert(pair<char, int>('H', 400));
}

map<tuple<int, int, char>, int> parseData()
{

    ifstream infile;
    infile.open("data.csv");

    map<tuple<int, int, char>, int> data;
    int regionNo, salesmanNo, quantity;
    char productId;

    while (infile >> regionNo >> salesmanNo >> productId >> quantity)
    {
        auto temp = make_tuple(regionNo, salesmanNo, productId);
        data[temp] += quantity;
    }
    return data;
}

map<pair<int, int>, int> convertData(map<tuple<int, int, char>, int> &data)
{

    map<pair<int, int>, int> totalSale;

    for (auto i : data)
        totalSale[pair<int, int>(get<0>(i.first), get<1>(i.first))] += i.second * prices[get<2>(i.first)];

    return totalSale;
}

void outputData(map<pair<int, int>, int> &totalSale)
{
    ofstream outfile;
    outfile.open("output.txt");

    outfile << setw(50) << "ABC Company" << endl
            << endl
            << endl;

    int region = totalSale.begin()->first.first;
    int sum = 0;

    outfile << "Region " << region << endl
            << endl;

    for (auto i : totalSale)
    {
        if (i.first.first != region)
        {
            outfile << endl
                    << "Total Sale at Region " << region << setw(13) << "Rs. " << sum << "/-" << endl
                    << endl
                    << endl;
            sum = 0;
            region = i.first.first;

            outfile << "Region " << region << endl
                    << endl;
        }

        outfile << "Salesman " << i.first.second << setw(25) << "Rs. " << i.second << "/-" << endl;
        sum += i.second;
    }

    outfile << endl
            << "Total Sale at Region " << region << setw(13) << "Rs. " << sum << "/-" << endl;
}

int main()
{
    initPrices();

    map<tuple<int, int, char>, int> data = parseData();

    map<pair<int, int>, int> totalSale = convertData(data);

    outputData(totalSale);
}
