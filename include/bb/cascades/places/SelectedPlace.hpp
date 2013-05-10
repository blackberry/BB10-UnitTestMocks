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
#ifndef BB_CASCADES_PLACES_SELECTEDPLACE_HPP
#define BB_CASCADES_PLACES_SELECTEDPLACE_HPP
#include "gtest/gtest.h"
#include <bb/cascades/places/Global>
#include <bb/cascades/places/SelectedPlaceImageType>
#include <QtDeclarative/QtDeclarative>
#include <QUrl>
#include <QString>
namespace bb
{
namespace cascades
{
namespace places
{
class SelectedPlacePrivate;
class QT_CASCADES_EXPORT BB_CASCADES_PLACES_EXPORT SelectedPlace : public QObject
{
public:
	virtual ~SelectedPlace();
public:
	MOCK_CONST_METHOD0(isPhysicalLocation, bool ());
	MOCK_CONST_METHOD0(id, int ());
	MOCK_CONST_METHOD0(name, QString ());
	MOCK_CONST_METHOD0(alternativeName, QString ());
	MOCK_CONST_METHOD0(description, QString ());
	MOCK_CONST_METHOD0(street, QString ());
	MOCK_CONST_METHOD0(city, QString ());
	MOCK_CONST_METHOD0(region, QString ());
	MOCK_CONST_METHOD0(country, QString ());
	MOCK_CONST_METHOD0(postal, QString ());
	MOCK_CONST_METHOD0(addressLabel, QString ());
	MOCK_CONST_METHOD0(phone, QString ());
	MOCK_CONST_METHOD0(secondaryPhone, QString ());
	MOCK_CONST_METHOD0(fax, QString ());
	MOCK_CONST_METHOD0(email, QString ());
	MOCK_CONST_METHOD0(url, QUrl ());
	MOCK_CONST_METHOD0(rating, double ());
	MOCK_CONST_METHOD0(mapURL, QUrl ());
	MOCK_CONST_METHOD1(getRawImage, QByteArray (SelectedPlaceImageType::Type& imageType));
	MOCK_CONST_METHOD0(image, QVariant ());
	MOCK_CONST_METHOD0(latitude, double ());
	MOCK_CONST_METHOD0(longitude, double ());
	MOCK_CONST_METHOD0(altitude, double ());
	MOCK_CONST_METHOD0(horizontalAccuracy, double ());
	MOCK_CONST_METHOD0(verticalAccuracy, double ());
#endif
