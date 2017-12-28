#include "PrevHeader.h"
#include "TestMap.h"


TestMap::TestMap()
{
}


TestMap::~TestMap()
{
}

bool TestMap::Init()
{
	block = Sprite::Create(L"Resources/block.png");

	character = Sprite::Create(L"Resources/Player.png");

	puts("Init");

	AddChild(block);
	AddChild(character);


	return true;
}

void TestMap::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	float x = Input::GetInstance()->GetMousePosition().x;
	float y = Input::GetInstance()->GetMousePosition().y;

	character->PositionSet(x, y);

	auto a = PixelPerfectCollision(block, character);

	printf("a : %d\n", a);

}

void TestMap::Render()
{
	Scene::Render();
}

int TestMap::PixelPerfectCollision(Sprite * sp1, Sprite * sp2)
{
	RECT rect1;
	rect1.left = (long)sp1->GetPosition().x;
	rect1.top = (long)sp1->GetPosition().y;
	rect1.right = (long)sp1->GetPosition().x + sp1->GetSize().x;
	rect1.bottom = (long)sp1->GetPosition().y + sp1->GetSize().y;

	RECT rect2;
	rect2.left = (long)sp2->GetPosition().x;
	rect2.top = (long)sp2->GetPosition().y;
	rect2.right = (long)sp2->GetPosition().x + sp2->GetSize().x;
	rect2.bottom = (long)sp2->GetPosition().y + sp2->GetSize().y;

	RECT dest;
	if (IntersectRect(&dest, &rect1, &rect2))
	{
		D3DLOCKED_RECT rectS1;
		HRESULT hr = sp1->GetTexture()->GetD3DTexture()->LockRect(0, &rectS1, NULL, NULL);
		if (FAILED(hr))
		{
			printf("FAILED 1 \n");
			return 0;
		}

		D3DLOCKED_RECT rectS2;
		HRESULT hr2 = sp2->GetTexture()->GetD3DTexture()->LockRect(0, &rectS2, NULL, NULL);
		if (FAILED(hr2))
		{
			printf("FAILED 2 \n");
			return 0;
		}

		D3DCOLOR* pixelsS1 = (D3DCOLOR*)rectS1.pBits; //잠거진 버퍼의 선두주소를 가져온다
		D3DCOLOR* pixelsS2 = (D3DCOLOR*)rectS2.pBits;

		for (int rx = dest.left; rx < dest.right; rx++) //dest는 sprite 두 개가 교차한 영역
		{
			for (int ry = dest.top; ry < dest.bottom; ry++)
			{
				//밑은 화면 좌표를 텍스쳐 좌표로
				int s1x = rx - sp1->GetPosition().x;
				int s1y = ry - sp1->GetPosition().y;

				int s2x = rx - sp2->GetPosition().x;
				int s2y = ry - sp2->GetPosition().y;

				printf("s1x : %d , s1y : %d \ns2x : %d , s2y : %d\n", s1x, s1y, s2x, s2y);

				//printf("byte a : %d\n", s1y * (int)sp1->GetSize().x + s1x);
				//printf("byte b : %d\n", s2y * (int)sp2->GetSize().x + s2x);

				//printf("pixelsS1[0] : %d , %c , %f\n", pixelsS1[s1y * 128 + s1x], pixelsS1[s1y * 128 + s1x], pixelsS1[s1y * 128 + s1x]);

				BYTE a = (pixelsS1[s1y * (int)sp1->GetSize().x + s1x] & 0xFF000000) >> 24;
				BYTE b = (pixelsS2[s2y * (int)sp2->GetSize().x + s2x] & 0xFF000000) >> 24;

				printf("a : %d\nb: %d\n", a, b);

				if (a == 255 && b == 255)
				{
					sp1->GetTexture()->GetD3DTexture()->UnlockRect(0);
					sp2->GetTexture()->GetD3DTexture()->UnlockRect(0);
					printf("collision!\n");
					return 1;
				}
			}
		}

		sp1->GetTexture()->GetD3DTexture()->UnlockRect(0);
		sp2->GetTexture()->GetD3DTexture()->UnlockRect(0);
		return 0;
	}

	return 0;
}