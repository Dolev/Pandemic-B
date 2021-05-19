#pragma once
#include <string>
#include <set>
#include <map>
#include "Color.hpp"
namespace pandemic{
	enum City { Algiers, Atlanta, Baghdad, Bangkok, Beijing, Bogota, BuenosAires, Cairo, Chennai, Chicago, Delhi, Essen, HoChiMinhCity, HongKong, Istanbul, Jakarta, Johannesburg, Karachi, Khartoum, Kinshasa, Kolkata, Lagos, Lima, London, LosAngeles, Madrid, Manila, MexicoCity, Miami, Milan, Montreal, Moscow, Mumbai, NewYork, Osaka, Paris, Riyadh, SanFrancisco, Santiago, SaoPaulo, Seoul, Shanghai, StPetersburg, Sydney, Taipei, Tehran, Tokyo, Washington };
	//connections;
	static std::set<City> Cities_Map[48] = {
		{ Madrid, Paris, Istanbul, Cairo },
		{ Chicago, Miami, Washington },
		{ Tehran, Istanbul, Cairo, Riyadh, Karachi },
		{ Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong },
		{ Shanghai, Seoul },
		{ MexicoCity, Lima, Miami, SaoPaulo, BuenosAires },
		{ Bogota, SaoPaulo },
		{ Algiers, Istanbul, Baghdad, Khartoum, Riyadh },
		{ Mumbai, Delhi, Kolkata, Bangkok, Jakarta },
		{ SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal },
		{ Tehran, Karachi, Mumbai, Chennai, Kolkata },
		{ London, Paris, Milan, StPetersburg },
		{ Jakarta, Bangkok, HongKong, Manila },
		{ Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei },
		{ Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow },
		{ Chennai, Bangkok, HoChiMinhCity, Sydney },
		{ Kinshasa, Khartoum },
		{ Tehran, Baghdad, Riyadh, Mumbai, Delhi },
		{ Cairo, Lagos, Kinshasa, Johannesburg },
		{ Lagos, Khartoum, Johannesburg },
		{ Delhi, Chennai, Bangkok, HongKong },
		{ SaoPaulo, Khartoum, Kinshasa },
		{ MexicoCity, Bogota, Santiago },
		{ NewYork, Madrid, Essen, Paris },
		{ SanFrancisco, Chicago, MexicoCity, Sydney },
		{ London, NewYork, Paris, SaoPaulo, Algiers },
		{ Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong },
		{ LosAngeles, Chicago, Miami, Lima, Bogota },
		{ Atlanta, MexicoCity, Washington, Bogota },
		{ Essen, Paris, Istanbul },
		{ Chicago, Washington, NewYork },
		{ StPetersburg, Istanbul, Tehran },
		{ Karachi, Delhi, Chennai },
		{ Montreal, Washington, London, Madrid },
		{ Taipei, Tokyo },
		{ Algiers, Essen, Madrid, Milan, London },
		{ Baghdad, Cairo, Karachi },
		{ LosAngeles, Chicago, Tokyo, Manila },
		{ Lima },
		{ Bogota, BuenosAires, Lagos, Madrid },
		{ Beijing, Shanghai, Tokyo },
		{ Beijing, HongKong, Taipei, Seoul, Tokyo },
		{ Essen, Istanbul, Moscow },
		{ Jakarta, Manila, LosAngeles },
		{ Shanghai, HongKong, Osaka, Manila },
		{ Baghdad, Moscow, Karachi, Delhi },
		{ Seoul, Shanghai, Osaka, SanFrancisco },
		{ Atlanta, NewYork, Montreal, Miami }
	};
	static City index_for_city(const int i) { return static_cast<City>(i); }
	static const std::string City_Names[] = { "Algiers", "Atlanta", "Baghdad", "Bangkok", "Beijing", "Bogota", "BuenosAires", "Cairo", "Chennai", "Chicago", "Delhi", "Essen", "HoChiMinhCity", "HongKong", "Istanbul", "Jakarta", "Johannesburg", "Karachi", "Khartoum", "Kinshasa", "Kolkata", "Lagos", "Lima", "London", "LosAngeles", "Madrid", "Manila", "MexicoCity", "Miami", "Milan", "Montreal", "Moscow", "Mumbai", "NewYork", "Osaka", "Paris", "Riyadh", "SanFrancisco", "Santiago", "SaoPaulo", "Seoul", "Shanghai", "StPetersburg", "Sydney", "Taipei", "Tehran", "Tokyo", "Washington" };
	static const Color City_Colors[] = { Black, Blue, Black, Red, Red, Yellow, Yellow, Black, Black, Blue, Black, Blue, Red, Red, Black, Red, Yellow, Black, Yellow, Yellow, Black, Yellow, Yellow, Blue, Yellow, Blue, Red, Yellow, Yellow, Blue, Blue, Black, Black, Blue, Red, Blue, Black, Blue, Yellow, Yellow, Red, Red, Blue, Red, Red, Black, Red, Blue };
	static const std::string Cities_Colors2[] = { "Black", "Blue", "Black", "Red", "Red", "Yellow", "Yellow", "Black", "Black", "Blue", "Black", "Blue", "Red", "Red", "Black", "Red", "Yellow", "Black", "Yellow", "Yellow", "Black", "Yellow", "Yellow", "Blue", "Yellow", "Blue", "Red", "Yellow", "Yellow", "Blue", "Blue", "Black", "Black", "Blue", "Red", "Blue", "Black", "Blue", "Yellow", "Yellow", "Red", "Red", "Blue", "Red", "Red", "Black", "Red", "Blue" };
}