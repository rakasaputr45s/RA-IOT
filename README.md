# RANCANG BANGUN ALAT MONITORING pH AIRLIMBAH BERBASIS IoT

![image](https://user-images.githubusercontent.com/100151123/155025374-5279da2e-7c08-48b5-91cb-bd46fd25e72c.png)

## Kalibrasi

### Persiapan Alat
* Air le Mineral/Akuades
* Larutan Buffer Ph 4 dan 6.86
* 3 Wadah air 250ml

### Proses Kalibrasi
* Bersihkan probe Ph dengan mencelupkan air yg tidak tercampur larutan Ph, lalu keringkan dengan tisu
* Celupkan Probe kedalam larutan Ph 4.01 dan tunggu sampai 2 menit
![IMG_20220222_012011](https://user-images.githubusercontent.com/100151123/155023076-2b60c2b7-f380-4ca3-a71f-946b73c1943d.jpg)
* Buka Arduino IDE dan Serial Monitor untuk melihat tegangan sensor ketika dimasukkan larutan Ph 4.01 mendapatkan tegangan di 4.85 V
 ![Pengujian 3 4 01](https://user-images.githubusercontent.com/100151123/155023388-b198bb6c-7075-4a17-bb33-01e31692e522.jpg)
* Bersihkan dan keringkan lagi probe
* Sekarang ganti celupkan probe kedalam larutan pH yang 6.86 dan tunggu selama 2 menit
![IMG_20220222_012205](https://user-images.githubusercontent.com/100151123/155023661-1d52252f-628c-401f-97ff-4760fc413aa7.jpg)
* Buka Arduino IDE dan Serial Monitor untuk melihat tegangan sensor ketika dimasukkan larutan Ph 6.86 mendapatkan tegangan di 4.50 V
![Pengujian 3 6 86](https://user-images.githubusercontent.com/100151123/155023607-4b8fe129-2296-42d0-911c-2ca27bee1f3b.jpg)
* Berikut tabel dari tegangan sensor di laturan pH 4.01 dan 6.86

| Voltage  | pH Value |
| ----- | --- |
| 4.87   | 4.01  |
| 4.50 | 6.86  |

* Buka link https://www.graphpad.com/quickcalcs/linear1/ untuk mencari persamaan linier regresi dengan cara memasukkan nilai tegangan dan pH dari tabel diatas 
![image](https://user-images.githubusercontent.com/100151123/155026175-85e87062-0984-4cfc-bf83-dcc59ecae615.png)
* Hasil perhitungan linier regresi menghasilkan persamaan Y = -7.703*X + 41.52
![image](https://user-images.githubusercontent.com/100151123/155026324-da3294b1-e3f4-488a-af8a-177f5b2d8680.png)
* Kopi hasil persamaan ke dalam program dan upload program tersebut
![image](https://user-images.githubusercontent.com/100151123/155026681-d7103d73-5d8c-4d58-b905-daab72be754e.png)
* Selesai
* "Untuk menjaga kestabilan dalam pembacaan sensor pH dibutuhkanlah nilai Linier Regresi yang mana sensor pH memiliki karakteristik perubahan tegangan sebanding dengan nilai pH"

## Pengujian Alat
### Tabel Pengujian 
| Larutan ph  | pH Value |
| ----- | --- |
| 4.01   | 4.1  |
| 6.86 | 6.6  |
### Gambar pengujian larutan pH 4.01 pada alat dan aplikasi BLYNK
![IMG_20220222_012041](https://user-images.githubusercontent.com/100151123/155026978-f94611f2-bb84-4ad3-b372-e3e0f4d53813.jpg)
![Pengujian pH 4 01 BLYNK](https://user-images.githubusercontent.com/100151123/155027047-5ccd7a27-15f0-49af-a2cc-35779eb50363.png)

### Gambar pengujian larutan pH 6.86 pada alat dan aplikasi BLYNK
![IMG_20220222_012615](https://user-images.githubusercontent.com/100151123/155027173-14ee21fa-e2c5-4a3a-9adb-4bcd5da4f2c8.jpg)
![Pengujian pH 6 86 BLYNK](https://user-images.githubusercontent.com/100151123/155027144-8d98d6a0-09f3-42f5-add4-6022d4514cd9.png)







