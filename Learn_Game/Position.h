#pragma once
namespace kr
{
	class Position
	{
	private:
		float x;
		float y;
	public:
		Position();
		Position(float x, float y);
		const float getX();
		const float getY();
		void setX(const float x);
		void setY(const float y);
		~Position();
	};
};

