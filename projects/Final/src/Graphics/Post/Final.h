#pragma once

#include "Graphics/Post/PostEffect.h"

class Final : public PostEffect
{
public:
	//Initializes framebuffer
	//Overrides post effect Init
	void Init(unsigned width, unsigned height) override;

	//Applies the effect to this buffer
	//passes the previous framebuffer with the texture to apply as parameter
	void ApplyEffect(PostEffect* buffer) override;

	//Getters
	float GetFocalLength() const;
	float GetAparture() const;
	float GetPlaneInFocus() const;


	//Setters
	void SetFocalLength(float focalLength);
	void SetAparture(float aparture);
	void SetPlaneInFocus(float planeinfocus);


private:
	float _focalLength = 1.0f;
	float _aparture = 1.0f;
	float _planeinfocus = 1.0f;

};