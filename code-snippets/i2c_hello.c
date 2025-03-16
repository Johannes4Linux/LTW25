/* Benötigter Header */
#include <linux/i2c.h>

/* Benenne alle kompatiblen Geräte */
static struct i2c_device_id my_ids[] = {
	{"my_dev"},
	{} /* leeres Element signalisiert das Ende der Liste */
};
MODULE_DEVICE_TABLE(i2c, my_ids);

/* Funktion wird aufgerufen, wenn ein kompatibles I2C Gerät hinzugefügt wird */
static int my_probe(struct i2c_client *client, const struct i2c_device_id * id)
{
	printk("Hallo vom I2C Slave mit der Adresse: 0x%x\n", client->addr);
	return 0;
}

/* Funktion wird aufgerufen, wenn ein kompatibles I2C Gerät entfernt wird */
static void my_remove(struct i2c_client *client)
{
	printk("Bye, bye, I2C\n");
}

/* Fasse kompatible Geräte, Probe- und Remove-Funktionen in Treiber zusammen */
static struct i2c_driver my_driver = {
	.probe = my_probe,
	.remove = my_remove,
	.id_table = my_ids,
	.driver = {
		.name = "my-i2c-driver",
	}
};
/* Registriere Treiber */
module_i2c_driver(my_driver);
/* Informationen über Treiber */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Johannes Roith");
MODULE_DESCRIPTION("Ein Hello World I2C Teiber");
