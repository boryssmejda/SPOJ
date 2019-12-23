#include "MaxDistance.hpp"
#include <iostream>

int main(void)
{
    MainInfo mInfo;
    mInfo.collectInput();

    vector<pair<int,int>> points(mInfo.m_numThings);
    for(std::size_t i = 0; i < points.size(); ++i)
    {
        std::cin >> points[i].first >> points[i].second;
    }

    MaxPoints maxP(mInfo, std::move(points));

    std::cout << maxP.maxNumThings() << "\n";

    return 0;
}