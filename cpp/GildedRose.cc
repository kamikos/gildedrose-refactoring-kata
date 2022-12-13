#include "GildedRose.h"


GildedRose::GildedRose(::std::vector<Item> const& items) : items(items)
{}

GildedRose::GildedRose(::std::vector<Item> && items) : items(::std::move(items))
{}

void GildedRose::updateQuality()
{
    std::string nameBackstage = "Backstage passes to a TAFKAL80ETC concert";
    std::string nameAged = "Aged Brie";
    std::string nameSulfuras = "Sulfuras, Hand of Ragnaros";


    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != nameAged && items[i].name != nameBackstage)
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != nameSulfuras)
                {
                    items[i].quality--;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality++;

                if (items[i].name == nameBackstage)
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }
                }
            }
        }

        if (items[i].name != nameSulfuras)
        {
            items[i].sellIn--;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != nameAged)
            {
                if (items[i].name != nameBackstage)
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != nameSulfuras)
                        {
                            items[i].quality--;
                        }
                    }
                }
                else
                {
                    items[i].quality = 0;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality++;
                }
            }
        }
    }
}
