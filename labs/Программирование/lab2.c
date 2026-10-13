#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>


int N = 100000;
double eps = 0.0000001;
double delta = 0.0001;
const double PI = 3.1415;



double ex_tl(double x) {
    double ex = 0;
    int n = 0;
    double step = 1;
    ex += step;
    while (step > eps || step < -1 * eps) {
        n++;
        step = step * (x / n);
        ex += step;
    }
    return ex;
}


double ln_tl(double x) {
    double lnx = 0;
    double n = 1;
    double step  = x;
    lnx += step;
    while (step > eps || step < -1 * eps) {
        n++;
        step = -step * x * ((n - 1) / n);
        lnx += step;
    }
    return lnx;
}


double sin_tl(double x) {
    double sinx = 0;
    double n = 1;
    double step = x;
    sinx += step;
    while (step > eps || step < -1 * eps) {
        step = step * (-((x * x) / ((n + 1) * (n + 2))));
        sinx += step;
        n += 2;
    }
    return sinx;
}


double cos_tl(double x) {
    double cosx = 0;
    double n = 0;
    double step  = 1;
    cosx += step;
    while (step > eps || step < -1 * eps) {
        step = step * (-((x * x) / ((n + 1) * (n + 2))));
        cosx += step;
        n += 2;
    }
    return cosx;
}

double arctg_tl(double x) {
    double arctgx = 0;
    double n = 1;
    double step  = x;
    arctgx += step;
    while (step > eps || step < -1 * eps) {
        step = step * (-((x * x) * (n / (n + 2))));
        arctgx += step;
        n += 2;
    }
    return arctgx;
}


double sqrt_tl(double x) {
    if (x <= 0) return 0;
    double res = x;
    double step = 0.5 * (res + (x / res));
    double diff = res - step;
    while (diff > eps || diff < -eps) {
        res = step;
        step = 0.5 * (res + (x / res));
        diff = res - step;
    }
    return res;
}


void var_0_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = exp(-(x * x)) * cos(3 * x);
        double y_tl = ex_tl(-(x * x)) * cos_tl(3 * x);
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_0_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < 1 && b > 1) {
        double h1 = ((1 - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((sin(x) + cos(x)) / (x * x - 1)) * h1;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - 1)) * h1;
        }
        double h2 = (b - (1 + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (1 + delta) + (i + 0.5) * h2;
            sum += ((sin(x) + cos(x)) / (x * x - 1)) * h2;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - 1)) * h2;
        }
    } else if (a < -1 && b > -1) {
        double h1 = ((-1 - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((sin(x) + cos(x)) / (x * x - 1)) * h1;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - 1)) * h1;
        }
        double h2 = (b - (-1 + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (-1 + delta) + (i + 0.5) * h2;
            sum += ((sin(x) + cos(x)) / (x * x - 1)) * h2;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - 1)) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += ((sin(x) + cos(x)) / (x * x - 1)) * h;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - 1)) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_1_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = sin(x) / (1 + x * x);
        double y_tl = sin_tl(x) / (1 + x * x);
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_1_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < 0 && b > 0) {
        double h1 = (-delta - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += (exp(x) - 1 - x) / (x * x) * h1;
            sum_tl += (ex_tl(x) - 1 - x) / (x * x) * h1;
        }
        double h2 = (b - delta) / N;
        for (int i = 0; i < N; i++) {
            double x = delta + (i + 0.5) * h2;
            sum += (exp(x) - 1 - x) / (x * x) * h2;
            sum_tl += (ex_tl(x) - 1 - x) / (x * x) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += (exp(x) - 1 - x) / (x * x) * h;
            sum_tl += (ex_tl(x) - 1 - x) / (x * x) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_2_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = atan(x) / (1 + x * x);
        double y_tl = arctg_tl(x) / (1 + x * x);
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_2_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < 0 && b > 0) {
        double h1 = (-delta - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((tan(x) - x) / (x * x * x)) * h1;
            sum_tl += ((sin_tl(x) / cos_tl(x) - x) / (x * x * x)) * h1;
        }
        double h2 = (b - delta) / N;
        for (int i = 0; i < N; i++) {
            double x = delta + (i + 0.5) * h2;
            sum += ((tan(x) - x) / (x * x * x)) * h2;
            sum_tl += ((sin_tl(x) / cos_tl(x) - x) / (x * x * x)) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += ((tan(x) - x) / (x * x * x)) * h;
            sum_tl += ((sin_tl(x) / cos_tl(x) - x) / (x * x * x)) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_3_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = log(1 + x * x) / (1 + x * x);
        double y_tl = ln_tl(x * x) / (1 + x * x);
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_3_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < 2 && b > 2) {
        double h1 = ((2 - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((atan(x) + 1) / (x * x - 4)) * h1;
            sum_tl += ((arctg_tl(x) + 1) / (x * x - 4)) * h1;
        }
        double h2 = (b - (2 + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (2 + delta) + (i + 0.5) * h2;
            sum += ((atan(x) + 1) / (x * x - 4)) * h2;
            sum_tl += ((arctg_tl(x) + 1) / (x * x - 4)) * h2;
        }
    } else if (a < -2 && b > -2) {
        double h1 = ((-2 - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((atan(x) + 1) / (x * x - 4)) * h1;
            sum_tl += ((arctg_tl(x) + 1) / (x * x - 4)) * h1;
        }
        double h2 = (b - (-2 + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (-2 + delta) + (i + 0.5) * h2;
            sum += ((atan(x) + 1) / (x * x - 4)) * h2;
            sum_tl += ((arctg_tl(x) + 1) / (x * x - 4)) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += ((atan(x) + 1) / (x * x - 4)) * h;
            sum_tl += ((arctg_tl(x) + 1) / (x * x - 4)) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_4_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = (sin(x) + cos(x)) / (2 + cos(x));
        double y_tl = (sin_tl(x) + cos_tl(x)) / (2 + cos_tl(x));
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_4_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < PI && b > PI) {
        double h1 = ((PI - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((sin(x) + cos(x)) / (x * x - PI * PI)) * h1;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - PI * PI)) * h1;
        }
        double h2 = (b - (PI + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (PI + delta) + (i + 0.5) * h2;
            sum += ((sin(x) + cos(x)) / (x * x - PI * PI)) * h2;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - PI * PI)) * h2;
        }
    } else if (a < -PI && b > -PI) {
        double h1 = ((-PI - delta) - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += ((sin(x) + cos(x)) / (x * x - PI * PI)) * h1;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - PI * PI)) * h1;
        }
        double h2 = (b - (-PI + delta)) / N;
        for (int i = 0; i < N; i++) {
            double x = (-PI + delta) + (i + 0.5) * h2;
            sum += ((sin(x) + cos(x)) / (x * x - PI * PI)) * h2;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - PI * PI)) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += ((sin(x) + cos(x)) / (x * x - PI * PI)) * h;
            sum_tl += ((sin_tl(x) + cos_tl(x)) / (x * x - PI * PI)) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


void var_5_b(double a, double b) {
    double h = (b - a) / N;
    double sum = 0;
    double sum_tl = 0;
    for (int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        double y = exp(-(x * x)) * sin(1 / (1 + x * x));
        double y_tl = ex_tl(-(x * x)) * sin_tl(1 / (1 + x * x));
        sum += y;
        sum_tl += y_tl;
    }
    sum *= h;
    sum_tl *= h;
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}

void var_5_h(double a, double b) {
    double sum = 0;
    double sum_tl = 0;
    if (a < 0 && b > 0) {
        double h1 = (-delta - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h1;
            sum += (((exp(x) - 1) / x) * cos(x)) * h1;
            sum_tl += (((ex_tl(x) - 1) / x) * cos_tl(x)) * h1;
        }
        double h2 = (b - delta) / N;
        for (int i = 0; i < N; i++) {
            double x = delta + (i + 0.5) * h2;
            sum += (((exp(x) - 1) / x) * cos(x)) * h2;
            sum_tl += (((ex_tl(x) - 1) / x) * cos_tl(x)) * h2;
        }
    } else {
        double h = (b - a) / N;
        for (int i = 0; i < N; i++) {
            double x = a + (i + 0.5) * h;
            sum += (((exp(x) - 1) / x) * cos(x)) * h;
            sum_tl += (((ex_tl(x) - 1) / x) * cos_tl(x)) * h;
        }
    }
    printf("math.h: %f\n", sum);
    printf("tl: %f\n", sum_tl);
}


int main() {
    double a = 0, b = 0;
    char x = getch();
    bool mina = false;
    bool minb = false;
    bool dot = false;
    bool sw = false;
    double div = 10;
    while (x != 13) {
        printf("%c", x);
        if (x == '-' && !sw) {
            mina = true;
        } else if (x == '-' && sw) {
            minb = true;
        }
        if (x == ' ' && !sw) {
            sw = true;
            dot = false;
            div = 10;
            x = getch();
            continue;
        }
        if (x == '.' || x == ',') {
            dot = true;
            x = getch();
            continue;
        }
        if (x >= '0' && x <= '9') {
            if (!dot) {
                if (!sw) {
                    a *= 10;
                    a += x - '0';
                } else {
                    b *= 10;
                    b += x - '0';
                }
            } else {
                if (!sw) {
                    a += (x - '0') / div;
                } else {
                    b += (x - '0') / div;
                }
                div *= 10;
            }
        }
        x = getch();
    }
    if (mina) {
        a *= -1;
    }
    if (minb) {
        b *= -1;
    }
    printf("\n");
    var_1_b(a, b);
}
