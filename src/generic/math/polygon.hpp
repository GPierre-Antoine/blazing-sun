//
// Created by Pierre-Antoine on 14/11/2015.
//

#ifndef BLAZING_SUN_POLYGON_HPP
#define BLAZING_SUN_POLYGON_HPP

#include <vector>

#include "point.hpp"




namespace math
{

    template <typename T, unsigned char D>
    class polygon
    {
    public:
        template <typename U, unsigned char E>
        friend void swap (polygon<U,E> & first,polygon<U,E> & second);
        polygon () = default;
        polygon (std::initializer_list<math::geometric_point<T,D>> initializer_list);
        polygon (const polygon & lvalue);
        polygon (polygon && prvalue);

        polygon& operator= (polygon other);

        ~polygon();

    private:
        std::vector<math::geometric_point<T,D>> points;
    protected:

    public:
        void move_for(math::geometric_point<T,D>);

    };

    template <typename U, unsigned char E>
    void swap (polygon<U,E> & first,polygon<U,E> & second)
    {
        using std::swap;
        swap (first.points,second.points);
    }


    template <typename T, unsigned char D>
    polygon<T,D>::polygon (std::initializer_list<geometric_point<T, D>> initializer_list) : points (initializer_list)
    {}

    template <typename T, unsigned char D>
    polygon<T,D>::polygon (const polygon & lvalue)
    {
        std::copy (lvalue.points.begin(),lvalue.points.end(),points.begin());
    }

    template <typename T, unsigned char D>
    polygon<T,D>::polygon (polygon && prvalue) : points (std::move(prvalue.points))
    {

    }


    template <typename T, unsigned char D>
    polygon<T,D>::~polygon()
    {

    }


    template <typename T, unsigned char D>
    polygon<T,D>& polygon<T,D>::operator = (polygon<T,D> other)
    {
        swap (*this,other);
        return *this;
    }

    //<editor-fold desc="typedefs">
    template <typename T>
    using polygon_2d = polygon<T,2>;
    template <typename T>
    using polygon_3d = polygon<T,3>;
    //</editor-fold>

}//math

#endif //BLAZING_SUN_POLYGON_HPP