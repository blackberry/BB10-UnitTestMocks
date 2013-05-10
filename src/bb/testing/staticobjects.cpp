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
/*!
 * This file is for static objects your tests may need that no longer have
 * a definition (only a declaration).
 */

#include <bb/cascades/Color>
#include <bb/cascades/StockCurve>
#include <bb/cascades/AbstractAnimation>
namespace bb {

namespace cascades {
const Color Color::White(Color::fromRGBA(1.0f, 1.0f, 1.0f, 1.0f));          //  0   White
const Color Color::Black(Color::fromRGBA(0.0f, 0.0f, 0.0f, 1.0f));          //  1   Black
const Color Color::Red(Color::fromRGBA(1.0f, 0.0f, 0.0f, 1.0f));          //  2   Red
const Color Color::DarkRed(Color::fromRGBA(0.5f, 0.0f, 0.0f, 1.0f));          //  3   DarkRed
const Color Color::Green(Color::fromRGBA(0.0f, 1.0f, 0.0f, 1.0f));          //  4   Green
const Color Color::DarkGreen(Color::fromRGBA(0.0f, 0.5f, 0.0f, 1.0f));          //  5   DarkGreen
const Color Color::Blue(Color::fromRGBA(0.0f, 0.0f, 1.0f, 1.0f));          //  6   Blue
const Color Color::DarkBlue(Color::fromRGBA(0.0f, 0.0f, 0.5f, 1.0f));          //  7   DarkBlue
const Color Color::Cyan(Color::fromRGBA(0.0f, 1.0f, 1.0f, 1.0f));          //  8   Cyan
const Color Color::DarkCyan(Color::fromRGBA(0.0f, 0.5f, 0.5f, 1.0f));          //  9   DarkCyan
const Color Color::Magenta(Color::fromRGBA(1.0f, 0.0f, 1.0f, 1.0f));          // 10   Magenta
const Color Color::DarkMagenta(Color::fromRGBA(0.5f, 0.0f, 0.5f, 1.0f));          // 11   DarkMagenta
const Color Color::Yellow(Color::fromRGBA(1.0f, 1.0f, 0.0f, 1.0f));          // 12   Yellow
const Color Color::DarkYellow(Color::fromRGBA(0.5f, 0.5f, 0.0f, 1.0f));          // 13   DarkYellow
const Color Color::Gray(Color::fromRGBA(0.625f, 0.625f, 0.64f, 1.0f));     // 14   Gray
const Color Color::DarkGray(Color::fromRGBA(0.5f, 0.5f, 0.5f, 1.0f));          // 15   DarkGray
const Color Color::LightGray(Color::fromRGBA(0.75f, 0.75f, 0.75f, 1.0f));       // 16   LightGray
const Color Color::Transparent(Color::fromRGBA(0.0f, 0.0f, 0.0f, 0.0f));          // 17   Transparent

const StockCurve StockCurve::Linear;
const StockCurve StockCurve::SineOut;        
const StockCurve StockCurve::QuadraticOut;
const StockCurve StockCurve::CubicOut;
const StockCurve StockCurve::ExponentialOut;
const StockCurve StockCurve::QuarticOut;
const StockCurve StockCurve::QuinticOut; 
const StockCurve StockCurve::CircularOut;        
const StockCurve StockCurve::BackOut;
const StockCurve StockCurve::ElasticOut;        
const StockCurve StockCurve::DoubleElasticOut;        
const StockCurve StockCurve::BounceOut;        
const StockCurve StockCurve::DoubleBounceOut;        
const StockCurve StockCurve::SineInOut;
const StockCurve StockCurve::QuadraticInOut;
const StockCurve StockCurve::CubicInOut;
const StockCurve StockCurve::ExponentialInOut;
const StockCurve StockCurve::QuarticInOut;
const StockCurve StockCurve::QuinticInOut;
const StockCurve StockCurve::CircularInOut;
const StockCurve StockCurve::BackInOut;
const StockCurve StockCurve::ElasticInOut;
const StockCurve StockCurve::DoubleElasticInOut;
const StockCurve StockCurve::BounceInOut;
const StockCurve StockCurve::DoubleBounceInOut;        
const StockCurve StockCurve::SineIn;
const StockCurve StockCurve::QuadraticIn;
const StockCurve StockCurve::CubicIn;
const StockCurve StockCurve::ExponentialIn;
const StockCurve StockCurve::QuarticIn;
const StockCurve StockCurve::QuinticIn;   
const StockCurve StockCurve::CircularIn;  
const StockCurve StockCurve::BackIn;
const StockCurve StockCurve::ElasticIn;
const StockCurve StockCurve::DoubleElasticIn;
const StockCurve StockCurve::BounceIn;
const StockCurve StockCurve::DoubleBounceIn;

const int AbstractAnimation::RepeatForever = 0;

} // namespace cascades
} // namespace bb
