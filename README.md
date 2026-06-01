# Hastane-Y-netimi
 HospitaL management for c++
 
# 🏥 C++ ile Nesne Yönelimli Hastane Yönetim Sistemi

Bu proje, C++ dili kullanılarak geliştirilmiş, üniversite dönemi kapsamında hazırlanan bir **Hastane Personel ve Hasta Yönetim Sistemi** simülasyonudur. Projenin temel amacı, Nesne Yönelimli Programlama (OOP) prensiplerini gerçek hayat senaryoları üzerinde uygulamaktır.

## 🚀 Kullanılan OOP Prensipleri ve Teknikler

Projede temiz, genişletilebilir ve sürdürülebilir bir kod mimarisi kurulması adına şu yapılar kullanılmıştır:

* **Soyutlama & Soyut Sınıflar (Abstraction & Abstract Classes):** `Personel` sınıfı saf sanal fonksiyonlar (`pure virtual functions`) barındıran soyut bir ana sınıf (base class) olarak tasarlanmıştır. Bu sınıftan doğrudan nesne üretilemez.
* **Kalıtım (Inheritance):** `Doktor`, `Hemsire` ve `IdariPersonel` sınıfları, `Personel` sınıfından türetilerek kod tekrarı önlenmiştir.
* **Çok Biçimlilik (Polymorphism & Method Overriding):** `bilgiGoster()` ve `zamYap(double oran)` fonksiyonları alt sınıflarda `override` kelimesiyle ezilerek her personelin kendi kurallarına göre çalışması sağlanmıştır.
* **Kapsülleme (Encapsulation):** Kritik veriler `protected` ve `private` erişim belirteçleri ile korunmuş, dış dünyayla olan veri akışı güvenli `getter` metotları (örn: `getAdSoyad()`) ile sağlanmıştır.
* **Dinamik Bellek Yönetimi (Dynamic Memory Management):** Nesneler heap bellekte `new` anahtar kelimesiyle oluşturulmuş ve bellek sızıntılarını (memory leak) önlemek için program sonunda `delete` ile temizlenmiştir.
* **Dosya İşlemleri (File I/O):** `fstream` kütüphanesi kullanılarak doktorların yazdığı reçeteler kalıcı olarak `receteler.txt` dosyasına kaydedilmektedir.
