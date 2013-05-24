/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef cascades_color_h
#define cascades_color_h

#include <bb/cascades/resources/colorpaint.h>

namespace bb {
    namespace cascades {

    class Color : public ColorPaint {
    public:

        /*! @brief Predefined opaque white color */
        static const Color White;
        /*! @brief Predefined opaque black color */
        static const Color Black;
        /*! @brief Predefined opaque red color */
        static const Color Red;
        /*! @brief Predefined opaque dark red color */
        static const Color DarkRed;
        /*! @brief Predefined opaque green color */
        static const Color Green;
        /*! @brief Predefined opaque dark green color */
        static const Color DarkGreen;
        /*! @brief Predefined opaque blue color */
        static const Color Blue;
        /*! @brief Predefined opaque dark blue color */
        static const Color DarkBlue;
        /*! @brief Predefined opaque cyan color */
        static const Color Cyan;
        /*! @brief Predefined opaque dark cyan color */
        static const Color DarkCyan;
        /*! @brief Predefined opaque magenta color */
        static const Color Magenta;
        /*! @brief Predefined opaque dark magenta color */
        static const Color DarkMagenta;
        /*! @brief Predefined opaque yellow color */
        static const Color Yellow;
        /*! @brief Predefined opaque dark yellow color */
        static const Color DarkYellow;
        /*! @brief Predefined opaque gray color */
        static const Color Gray;
        /*! @brief Predefined opaque dark gray color */
        static const Color DarkGray;
        /*! @brief Predefined opaque light gray color */
        static const Color LightGray;
        /*! @brief Predefined transparent color */
        static const Color Transparent;

        Color(): _r(0.0f), _g(0.0f), _b(0.0f), _a(0.0f), _isNull(false) {

        }

        static Color fromRGBA(float red, float green, float blue, float alpha = 1.0f) {
        	return Color(red, green, blue, alpha);
        }

        static Color fromARGB(unsigned int argb) {
        	int a = (argb >> 24) & 0xff;
       	    int r = (argb >> 16) & 0xff;
       	    int g = (argb >> 8) & 0xff;
       	    int b = argb & 0xff;

      	    return Color(((float)r)/255.0f, ((float)g)/255.0f, ((float)b)/255.0f, ((float)a)/255.0f);
        }

        Color(const Color& orig) {
        	*this = orig;
        }

        Color& operator=(const Color& other) {
        	_r = other._r;
        	_g = other._g;
        	_b = other._b;
        	_a = other._a;
        	_isNull = other._isNull;

        	return *this;
        }

        virtual ~Color() { }

        virtual bool operator==(const Paint &other) const {
        	const Color* otherColor = dynamic_cast<const Color*>(&other);
        	if (otherColor) {
        		return
       		           this->_isNull == otherColor->_isNull &&
       		           this->_r == otherColor->_r &&
       		           this->_g == otherColor->_g &&
       		           this->_b == otherColor->_b &&
       		           this->_a == otherColor->_a;
        	}
        	return false;
        }

        virtual bool operator!=(const Paint &other) const {
        	return !(*this == other);
        }

        float alpha() const { return _a; }
        float red() const { return _r; }
        float green() const { return _g; }
        float blue() const { return _b; }
        bool isNull() const { return _isNull; }

    private:
        Color(float r, float g, float b, float alpha = 1.0f) {
           	_r = r;
           	_g = g;
           	_b = b;
           	_a = alpha;
           	_isNull = false;
        }
        float _r;
        float _g;
        float _b;
        float _a;
        bool _isNull;
    };
    /* @} */

}
}

Q_DECLARE_METATYPE(bb::cascades::Color)

#endif	/* cascades_color_h */

