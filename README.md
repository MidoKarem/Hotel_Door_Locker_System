# Hotel_Door_Locker_System

## Description
Hotel room locker software that enables the guests to keep their valuables by creating a password which can be changed afterwards, but not deleted when the microcontroller’s power fails


## Details
* First time password saved is 0000.
* Used should enter 0000 to open locker at first time.
* To change password user should press on ‘*’ , buzzer will be on for 3 second then off , user should enter 4 digit password then , press on ‘*’.
* Pressing on any button will make the buzzer on for 100msec.
* To close the locker, you should press only on ‘C’.
* To open the locker, enter 4 digit password.
* If you enter wrong password, a buzzer will be on for 3 second then off , re-enter password again.


## System Components
ATmega32 <br />
LCD <br />
Keypa <br />
Buzzer <br />
