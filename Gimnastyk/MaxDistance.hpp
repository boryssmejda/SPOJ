#ifndef MAX_DISTANCE_HPP
#define MAX_DISTANCE_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <memory>

using std::vector;
using std::pair;

struct MainInfo
{
    int m_numThings, m_time, m_obstWidth, m_wx, m_wy, m_velocity;

    void collectInput()
    {
        using std::cin;
        cin >> m_numThings >> m_time >> m_obstWidth >> m_wx >> m_wy >> m_velocity;
    }
};

enum class CalcBehaviour
{
    ZeroObstacle, WideObstacle
};

class I_DistanceBehaviour
{
    public:
        virtual int maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p) = 0;
        virtual ~I_DistanceBehaviour(){}
};

class NoObstacle final: public I_DistanceBehaviour
{
    private:
        double distanceFromRally(const pair<int, int>& t_p, int t_wx, int t_wy) const;
        void sortByDistance(vector<pair<int,int>>& t_p, int t_wx, int t_wy);
    public:
       virtual int maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p) override;
};


struct Point
{
    double x,y;
    double distFromRally;
    double timeFromRally;
};

class ThickObstacle final: public I_DistanceBehaviour
{
    private:
        vector<Point> m_sortedPoints;
        pair<double, double> findCoeffcients(Point t_a, Point t_rally);
        void sortByDistance(MainInfo& t_mInf, vector<pair<int,int>>& t_p);
        double calcDistanceFromRally(const pair<int, int>& p ,int t_wx, int t_wy, int t_obstWidth);
        double calcTime(double t_dist, int t_speed, int t_obstWidth);
        double distBetweenPoints(const Point& a, const Point& b);
    public:
        virtual int maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p) override;
};


class MaxPoints
{
    private:
        MainInfo m_info;
        vector<pair<int,int>> m_points;
        std::unique_ptr<I_DistanceBehaviour> dB;

    public:
        MaxPoints(MainInfo t_mInf, vector<pair<int,int>>&& t_p);
        int maxNumThings();
        void setBehaviour(CalcBehaviour t_beh);
};

#endif