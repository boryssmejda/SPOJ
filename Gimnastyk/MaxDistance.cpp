#include "MaxDistance.hpp"

#include <algorithm>
#include <cmath>
#include <memory>

MaxPoints::MaxPoints(MainInfo t_mInf, vector<pair<int,int>>&& t_p)
 {
        m_info   = std::move(t_mInf);
        m_points = std::move(t_p);

        if(m_info.m_obstWidth == 0)
            setBehaviour(CalcBehaviour::ZeroObstacle);
        else
            setBehaviour(CalcBehaviour::WideObstacle);
}


int MaxPoints::maxNumThings()
{
    return dB->maxNumThings(m_info, m_points);
}


void MaxPoints::setBehaviour(CalcBehaviour t_beh)
{
    using namespace std;
    switch (t_beh)
    {
        case CalcBehaviour::ZeroObstacle:
            dB = make_unique<NoObstacle>(); 
            break;
        case CalcBehaviour::WideObstacle:
            dB = make_unique<ThickObstacle>(); 
            break;
        default:
            break;
    }
}




double NoObstacle::distanceFromRally(const pair<int, int>& t_p, int t_wx, int t_wy) const
{
    int x_dist = (t_p.first - t_wx);
    int y_dist = (t_p.second - t_wy);

    return sqrt(x_dist*x_dist + y_dist*y_dist);
}

void NoObstacle::sortByDistance(vector<pair<int,int>>& t_p, int t_wx, int t_wy)
{
    auto sortByDist = [&](auto a, auto b)
    {
        return distanceFromRally(a, t_wx, t_wy) < distanceFromRally(b, t_wx, t_wy); 
    };

    std::sort(t_p.begin(), t_p.end(), sortByDist);
}

int NoObstacle::maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p)
{
    sortByDistance(t_p, t_mInf.m_wx, t_mInf.m_wy);
    double timeToUse = t_mInf.m_time/2.0;
    double maxDistance = t_mInf.m_velocity * timeToUse;

    int nrThings {0};
    double distSoFar {0};

    for(auto& p: t_p)
    {
        if( (distSoFar + distanceFromRally(p, t_mInf.m_wx, t_mInf.m_wy)) <= maxDistance )
        {
            distSoFar += distanceFromRally(p, t_mInf.m_wx, t_mInf.m_wy);
            nrThings++;
        }
        else
            break;
    }

    return nrThings;
}


double ThickObstacle::distBetweenPoints(const Point& a, const Point& b)
{
    int x_dist = a.x - b.x;
    int y_dist = a.y - b.y;
 
    return sqrt( (x_dist*x_dist+ y_dist*y_dist) );
}

pair<double, double> ThickObstacle::findCoeffcients(Point t_a, Point t_rally)
{
    double a = (t_rally.y - t_a.y)/static_cast<double>(t_rally.x - t_a.x);
    double b = t_rally.y - a * t_rally.x;

    return {a, b};
}


double ThickObstacle::calcDistanceFromRally(const pair<int, int>& p ,int t_wx, int t_wy, int t_obstWidth)
{
    auto [a,b] = findCoeffcients( {static_cast<double>(p.first), static_cast<double>(p.second),0,0}, 
        {static_cast<double>(t_wx), static_cast<double>(t_wy),0,0} );

    // four crucial Points
    Point rally {static_cast<double>(t_wx), static_cast<double>(t_wy), 0 ,0};
    Point target {static_cast<double>(p.first), static_cast<double>(p.second), 0 , 0};
    Point zeroCrossing {0, b, 0 ,0};
    Point obstEdge {static_cast<double>(t_obstWidth), (a*t_obstWidth + b) ,0 ,0};



    double distRallyandEdge     =  distBetweenPoints(rally, obstEdge);
    double distTargAndZeroCr    = distBetweenPoints(target, zeroCrossing);


    double finalDistance {0};
    if(distRallyandEdge > distTargAndZeroCr)
    {
        Point exitPoint = {0, (a*t_obstWidth + b), 0, 0};
        double tmpDist = distBetweenPoints(target, exitPoint);
        finalDistance = distRallyandEdge + t_obstWidth + tmpDist;
    }
    else
    {   
        Point edge = {static_cast<double>(t_obstWidth), (a*t_obstWidth + b),0 ,0 };
        double tmpDist = distBetweenPoints(rally, edge);
        finalDistance = distTargAndZeroCr + t_obstWidth + tmpDist;
    }

    return finalDistance;
}


double ThickObstacle::calcTime(double t_dist, int t_speed, int t_obstWidth)
{
    return ((t_dist - t_obstWidth)/static_cast<double>(t_speed) + t_obstWidth);
}


void ThickObstacle::sortByDistance(MainInfo& t_mInf, vector<pair<int,int>>& t_p)
{
    for(auto &p : t_p)
    {
        double dist = calcDistanceFromRally(p, t_mInf.m_wx, t_mInf.m_wy, t_mInf.m_obstWidth);   
        double time = calcTime(dist, t_mInf.m_velocity, t_mInf.m_obstWidth);

        Point point = {
            static_cast<double>(p.first), 
            static_cast<double>(p.second),
            dist,
            time,
        };
        
        m_sortedPoints.push_back(std::move(point));
    }

    auto cmp = [](auto a, auto b)
            {
               return a.timeFromRally < b.timeFromRally;
            };

    std::sort(m_sortedPoints.begin(), m_sortedPoints.end(), cmp);
}

int ThickObstacle::maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p)
{
    sortByDistance(t_mInf, t_p);

    double currentTime{0};
    int nrThings{0};

    // End part of the function
    for(auto& p: m_sortedPoints)
    {
        if(currentTime + p.timeFromRally <= t_mInf.m_time/2.0)
        {
            currentTime += p.timeFromRally;
            nrThings++;
        }
        else
        {
            break;
        }
        
    }

    return nrThings;
}


