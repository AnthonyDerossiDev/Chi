#include "DungeonMapWidget.h"

#include "DungeonTypes.h"
#include "Components/GridSlot.h"
#include "Components/Image.h"

void UDungeonMapWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

UImage* UDungeonMapWidget::GenerateImage()
{
	UImage* NewRoomImage = NewObject<UImage>(this);
	return NewRoomImage;
}


void UDungeonMapWidget::UpdateMap(const TArray<TArray<E_RoomType>>& NewMap)
{

	for (int32 Row = 0; Row < NewMap.Num(); ++Row)
	{
		for (int32 Col = 0; Col < NewMap[Row].Num(); ++Col)
		{
			FVector2D RoomPosition(Row,Col);
			AddRoom(RoomPosition, NewMap[Row][Col]);
			
		}
	}
}


