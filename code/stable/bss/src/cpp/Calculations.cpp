#include "Calculations.hpp"

#include <vector>

#include "ODE.hpp"
#include "Populate.hpp"
#include "boost/numeric/odeint/integrate/integrate_const.hpp"
#include "boost/numeric/odeint/stepper/generation.hpp"
#include "boost/numeric/odeint/stepper/runge_kutta_dopri5.hpp"

using std::vector;

vector<double> func_q(double m_2, double m_1, double x_1^0, double y_1^0, double x_2^0, double y_2^0, double v_x1^0, double v_y1^0, double v_x2^0, double v_y2^0, double t_final) {
    vector<double> q;
    ODE ode = ODE(m_1, m_2, x_1^0, y_1^0, x_2^0, y_2^0, v_x1^0, v_y1^0, v_x2^0, v_y2^0, t_final);
    vector<double> currVals{x_1^0, y_1^0, x_2^0, y_2^0, v_x1^0, v_y1^0, v_x2^0, v_y2^0};
    Populate pop = Populate(q);
    
    boost::numeric::odeint::runge_kutta_dopri5<vector<double>> rk = boost::numeric::odeint::runge_kutta_dopri5<vector<double>>();
    auto stepper = boost::numeric::odeint::make_controlled(1.0e-8, 1.0e-8, rk);
    boost::numeric::odeint::integrate_const(stepper, ode, currVals, 0.0, t_final, 10.0, pop);
    
    return q;
}
