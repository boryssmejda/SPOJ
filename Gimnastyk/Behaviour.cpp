#include "Behaviour.hpp"

double NoObstacle::distanceFromRally(const pair<int, int>& t_p) const
{
    int x_dist = (t_p.first - m_info.m_wx);
    int y_dist = (t_p.second - m_info.m_wy);

    return sqrt(x_dist*x_dist + y_dist*y_dist);
}

void NoObstacle::sortByDistance()
{
    auto sortByDist = [&](auto a, auto b)
    {
        return distanceFromRally(a) < distanceFromRally(b); 
    };

    std::sort(m_points.begin(), m_points.end(), sortByDist);
}

int NoObstacle::maxNumThings()
{
    sortByDistance();
    double timeToUse = m_info.m_time/2.0;
    double maxDistance = m_info.m_velocity * timeToUse;

    int nrThings {0};
    double distSoFar {0};

    for(auto& p: m_points)
    {
        if( (distSoFar + distanceFromRally(p)) <= maxDistance )
        {
            distSoFar += distanceFromRally(p);
            nrThings++;
        }
        else
            break;
    }

    return nrThings;
}

