#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

#include "MaxDistance.hpp"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

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
        double distanceFromRally(const pair<int, int>& t_p) const;
        void sortByDistance();
    public:
       virtual int maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p) override;
};

class ThickObstacle final: public I_DistanceBehaviour
{
    public:
        virtual int maxNumThings(MainInfo& t_mInf, vector<pair<int,int>>& t_p) override;
};

#endif