#ifndef KEYCONTROLS_HPP
#define KEYCONTROLS_HPP

//class keyControls
// variables: bool up,right,down,left
// used for keyControls
struct keyControls
{
        bool up;
        bool right;
        bool down;
        bool left;
	bool boost;
        keyControls()
        {
                up = 0;
                right = 0;
                down = 0;
                left = 0;
		boost = 0;
        }

	void getDirection();
};

#endif
