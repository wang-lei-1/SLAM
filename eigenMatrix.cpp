#include <iostream>
using namespace std;

#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

#define MATRIX_SIZE 50
int main(int argc, char const *argv[])
{
    //声明一个2*3的矩阵
    Matrix<float,2,3> matrix_23;

    //3行一列矩阵 Vector3d 是Eigen::Matrix<double ， 3，1>
    Vector3d v_3d;

    //定义一个float 类型的3*1的矩阵
    Matrix<float ,3,1> vd_3d;

    //此矩阵是double类型3*3的矩阵,并初始化为0
    Matrix3d Matrix_33 = Matrix3d::Zero();

    //不知道矩阵的行列是多少时，定一个dynamic的矩阵
    Matrix<double,Dynamic,Dynamic> matrix_dynamic;
    //更简单的
    MatrixXd matrix_x;

    //下面是对Eigen阵的操作
    //输入数据(初始化)
    matrix_23 << 1,2,3,4,5,6;
    //输出
    cout << "matrix 2x3 from 1 to 6 :\n" << matrix_23 <<endl;

    //用()访问矩阵中的元素
    cout << "print matrix 2x3 :" << endl;
    for(int i=0;i<2;i++)
    {
        for(int j= 0;j<3;j++)
        {
            cout << matrix_23(i,j) << "\t";
            cout << endl;
        }
    }

    //矩阵和向量相乘
    v_3d << 3,2,1;
    vd_3d << 4,5,6;
    Matrix<double ,2,1> result = matrix_23.cast<double>() * v_3d;
    cout << "[1,2,3,4,5,6]*[3,2,1] = " << result.transpose() << endl;

    //相关函数展示
    Matrix3d matrix_33 = Matrix3d::Random();
    cout << "random matrix :\n" <<matrix_33 << endl;
    cout << "transpose: \n" << matrix_33.transpose() <<endl;//转置
    cout << "sum :" << matrix_33.sum() <<endl;//求和
    cout << "trace :" << matrix_33.trace() << endl;
    cout << "inverse: " << matrix_33.inverse() << endl;//逆矩阵
    return 0;
}
