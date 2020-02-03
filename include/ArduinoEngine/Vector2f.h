#ifndef H_VECTOR2F
#define H_VECTOR2F


struct Vector2f {
    float x;
    float y;
    Vector2f(){}
    Vector2f(float _x, float _y): x(_x), y(_y){}

    friend inline bool operator==(const Vector2f& lhs, const Vector2f& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    inline Vector2f operator=(const Vector2f& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }
};
#endif
