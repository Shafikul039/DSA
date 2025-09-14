struct Point {
    double x, y;
};

double cross_product (Point &a, Point &b) {
    return a.x * b.y - a.y * b.x;
}

double cal_area (vector<Point> &points, ll n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cross_product (points[i], points[(i + 1) % n]);
    }
    return abs(sum) / 2.0;
}
