from sympy import Symbol, solve
from math import cos,pi

def calc_torque():
    # all weights in grams, lengths in cm, angles in degrees
    w1 = 55.0
    w2 = 55.0
    w3 = 55.0
    w_j1 = 10.0
    w_j23 = 13.5
    l1 = 140.0
    l2 = 75.0
    l3 = 40.0
    theta1 = 90.0  # set to 0.0 to check max conditions 
    theta2 = 45.0  # set to 90.0 to check max conditions

    w_j1 = 65.0
    w_j23 = 125.0
    w_frame = 70.0
    w_battery = 200.0
    w_arduino = 25.0
    w_body = w_frame + w_battery + w_arduino
    w_leg = w_j1 + w_j23
    w4 = w_body + 3*w_leg

    # sum: Torque at left foot 
    x_n2 =  Symbol("x_n2") 
    n2 = solve( \
        - (w_j1 + w_j23 + w4 + 2*w_leg - 2*x_n2)*l1*cos(theta1*pi/180.) \
        - (       w_j23 + w4 + 2*w_leg - 2*x_n2)*l2*cos(theta2*pi/180.) \
        - (               w4 + 2*w_leg - 2*x_n2)*l3 \
        - (                    2*w_leg - 2*x_n2)*l3 \
        - (                    2*w_leg - 2*x_n2)*l2*cos(theta2*pi/180.) \
        - (                            - 2*x_n2)*l1*cos(theta1*pi/180.) \
    )
    
    n2 = n2[0]
    print (n2)

    # total reaction force equals total weight
    # n1 + 2*n2 = w4 + 3*w_leg
    n1 = w4 + 3*w_leg - 2*n2
    print (n1)


    # sum: torque at knee
    T1 = n1*l1*cos(theta1) 
    + (       w_j23 + w4 + 2*w_leg - 2*n2)*l2*cos(theta2*pi/180.) 
    + (               w4 + 2*w_leg - 2*n2)*l3 
    + (                    2*w_leg - 2*n2)*l3 
    + (                    2*w_leg - 2*n2)*l2*cos(theta2*pi/180.) 
    + (                            - 2*n2)*l1*cos(theta1*pi/180.)  

    print ('T1:', round(T1/10000,2) , 'kg.cm')  

    # sum: torque at hip
    T2 = n1*l1*cos(theta1) + (n1 - w_j1)*l2*cos(theta2*pi/180.)
    + (               w4 + 2*w_leg - 2*n2)*l3
    + (                    2*w_leg - 2*n2)*l3
    + (                    2*w_leg - 2*n2)*l2*cos(theta2*pi/180.)
    + (                            - 2*n2)*l1*cos(theta1*pi/180.)        
    
    print ('T2:', round(T2/10000,2) , 'kg.cm')  

calc_torque()