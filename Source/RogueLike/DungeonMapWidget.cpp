#include "DungeonMapWidget.h"

#include "DungeonTypes.h"
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


void UDungeonMapWidget::UpdateMap(const TArray<TArray<E_RoomType>>& DungeonMap)
{

	for (int32 Row = 0; Row < DungeonMap.Num(); ++Row)
	{
		for (int32 Col = 0; Col < DungeonMap[Row].Num(); ++Col)
		{
			FVector2D RoomPosition(Row,Col);
			AddRoom(RoomPosition, DungeonMap[Row][Col]);
			
		}
	}
}


