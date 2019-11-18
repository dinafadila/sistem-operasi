# Latihan UASP

---

```bash
# pindah ke direktori home anda
cd
# buat satu folder kosong 'test'
mkdir test
# masuk ke direktori 'test'
cd test
# tampilkan path direktori saat ini
pwd
# buat file kosong bernama 'empty.txt'
touch empty.txt
```

---

```bash
# copy file '/etc/timezone' ke direktori ini
cp /etc/timezone
# ubah nama file 'timezone' menjadi 'tz.txt'
mv timezone tz.txt
# list isi direktori ini
ls
# pindah ke direktori parent
mv * ../
# hapus direktori 'test' seisinya
rm -r test
```

---

```bash
# temukan file dengan nama 'fdisk' memakai `locate`
locate 'fdisk'
# temukan file dengan nama 'fdisk' memakai `find`
find /home -name fdisk
# temukan file pada home anda yang ukurannya > 200 MB
find ./ -type f -size +200M
# temukan file pada home anda yang diubah < 3 hari
find ./ -type f -mtime -3
# temukan file pada home anda yang diakses > 30 hari
find ./ -type f -atime +30
```

---

```bash
# tampilkan 5 baris pertama keluaran perintah `last`
last | head -n 5
# tampilkan dua baris terakhir file '/etc/passwd'
tail -2 /etc/passwd
# cari file di '/usr/include' yang memuat kata 'sem_post'
grep -r "sem_post" /usr/include
# tampilkan kolom 1 dan 5 dari file '/etc/passwd'
cut -f 1,5 -d ':' /etc/passwd
# tampilkan isi file '/etc/motd' dalam huruf kapital
cat /etc/motd | tr "[a-z]" "[A-Z]"
```

---

```bash
# jalankan `cat /dev/random > rand.txt` di background
cat /dev/random > rand.txt &
# tampilkan daftar job
jobs
# kirim sinyal STOP ke job tersebut
kill -n 19 $(eval 'jobs -p')
# lanjutkan job tersebut di background
bg 1
# kirim sinyal TERM ke job tersebut
kill -n 15 $(eval 'jobs -p')
```

## Kisi-kisi

```
echo hostname uname date cal who
cd pwd ls touch
cp mv rm mkdir rmdir
chmod ln
locate find wc
cat head tail sort uniq cut tr grep sed
ps nice renice pidof kill
& jobs fg bg
```
