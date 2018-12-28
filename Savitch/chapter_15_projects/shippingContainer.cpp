#include <shippingContainer.hpp>
#include <iostream>
using namespace std;

namespace shipping_eric
{
	ShippingContainer::ShippingContainer() : id(0)
	{
		//empty
	}
	
	ShippingContainer::ShippingContainer(int the_id) : id(the_id)
	{
		//empty
	}
	
	ShippingContainer::ShippingContainer(const ShippingContainer& copy) : id(copy.id)
	{
		//empty
	}
	
	ShippingContainer& ShippingContainer::operator =(const ShippingContainer& right)
	{
		id = right.id;
		return *this;
	}
	
	string ShippingContainer::get_manifest()
	{
		return "";
	}
		
	int ShippingContainer::get_id()
	{
		return id;
	}
	
	void ShippingContainer::set_id(int new_id)
	{
		id = new_id;
	}
	
	ManualShippingContainer::ManualShippingContainer() : ShippingContainer(), manifest("")
	{
		//empty
	}
	
	ManualShippingContainer::ManualShippingContainer(int the_id, string the_manifest) : ShippingContainer(the_id), manifest(the_manifest)
	{
		//empty
	}
	
	ManualShippingContainer::ManualShippingContainer(const ManualShippingContainer& copy) : ShippingContainer(), manifest(copy.manifest)
	{
		//empty
	}
	
	ManualShippingContainer& ManualShippingContainer::operator =(const ManualShippingContainer& right)
	{
		ShippingContainer::operator =(right);
		manifest = right.manifest;
		return *this;
	}
		
	string ManualShippingContainer::get_manifest()
	{
		return manifest;
	}
	
	void ManualShippingContainer::set_manifest(std::string new_manifest)
	{
		manifest = new_manifest;
	}
	
	RFIDShippingContainer::RFIDShippingContainer() : ShippingContainer()
	{
		//empty
	}
	
	RFIDShippingContainer::RFIDShippingContainer(int the_id) : ShippingContainer(the_id)
	{
		//empty
	}
	
	RFIDShippingContainer::RFIDShippingContainer(const RFIDShippingContainer& copy)
		: ShippingContainer(copy)
	{
		//empty
	}
	
	RFIDShippingContainer& RFIDShippingContainer::operator =(const RFIDShippingContainer& right)
	{
		ShippingContainer::operator =(right);
		items = right.items;
		return *this;
	}
		
	std::string RFIDShippingContainer::get_manifest()
	{
		string result = "";
		for (vector<InventoryItem>::iterator it = items.begin(); it != items.end(); it++)
		{
			result += it->name + ": " + to_string(it->quantity) + "\n";
		}
		return result;
	}
	void RFIDShippingContainer::set_manifest(vector<InventoryItem> new_items)
	{
		items = new_items; 
	}
	
	void RFIDShippingContainer::add_item(std::string item_name)
	{
		InventoryItem new_item;
		new_item.name = item_name;
		new_item.quantity = 1;
		add_item_internal(new_item);
	}
	
	void RFIDShippingContainer::add_item(std::string item_name, int quantity)
	{
		InventoryItem new_item;
		new_item.name = item_name;
		new_item.quantity = quantity;
		add_item_internal(new_item);		
	}
	
	void RFIDShippingContainer::add_item_internal(InventoryItem new_item)
	{
		bool found = false;
		for (vector<InventoryItem>::iterator it = items.begin(); it != items.end(); it++)
		{
			if (it->name == new_item.name)
			{
				found = true;
				it->quantity += new_item.quantity;
			}
		}
		if (!found)
		{
			items.push_back(new_item);
		}	
	}
}
