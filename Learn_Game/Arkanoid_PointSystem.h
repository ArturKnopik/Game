#pragma once
namespace Arkanoid
{

	class PointSystem
	{
		int points;
		int pointPerHit;
		int basicPointMultipler;
		int maxPointMultipler;
		int buffedMultipler;
	public:
		PointSystem();
		PointSystem(int pointPerHit, int maxPointMultipler);
		~PointSystem()=default;
		void increaseBasicMultipler();
		void resetBasicMultipler();
		void increaseBuffMultipler(int multiplier);
		void resetBuffMultipler();
		void addPoints(int points);
		void reset();
		int getPoints();
		int getBasicMultipler();
		int getBuffMultipler();

	};
}
