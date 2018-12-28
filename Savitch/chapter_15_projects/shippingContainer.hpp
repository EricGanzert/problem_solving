#ifndef SHIPPING_CONTAINER_H
#define SHIPPING_CONTAINER_H
#include <string>
#include <vector>

namespace shipping_eric
{
	class ShippingContainer
	{
	public:
		ShippingContainer();
		ShippingContainer(int the_id);
		ShippingContainer(const ShippingContainer& copy);
		ShippingContainer& operator =(const ShippingContainer& right);
		
		virtual std::string get_manifest();
		
		int get_id();
		void set_id(int new_id);
		
	private:
		int id;
	};
	
	class ManualShippingContainer : public ShippingContainer
	{
	public:
		ManualShippingContainer();
		ManualShippingContainer(int the_id, std::string the_manifest);
		ManualShippingContainer(const ManualShippingContainer& copy);
		ManualShippingContainer& operator =(const ManualShippingContainer& right);
		
		virtual std::string get_manifest();
		void set_manifest(std::string new_manifest);
	private:
		std::string manifest;
	};
	
	struct InventoryItem
	{
		std::string name;
		int quantity;
	};
	
	class RFIDShippingContainer : public ShippingContainer
	{
	public:
		RFIDShippingContainer();
		RFIDShippingContainer(int the_id);
		RFIDShippingContainer(const RFIDShippingContainer& copy);
		RFIDShippingContainer& operator =(const RFIDShippingContainer& right);
		
		virtual std::string get_manifest();
		void set_manifest(std::vector<InventoryItem> new_items);
		void add_item(std::string item_name);
		void add_item(std::string item_name, int quantity);
	private:
		void add_item_internal(InventoryItem new_item);
		std::vector<InventoryItem> items;
	};
}

#endif //SHIPPING_CONTAINER_H
