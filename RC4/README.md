# RC4 – Stream Cipher (Two Independent Projects)

- RC4 tách thành thư viện: `include/rc4.h`, `src/rc4.c`.
- Hai project độc lập: `RC4_Encrypt/` và `RC4_Decrypt/`.
- `main.c` chỉ gọi hàm từ header (không chứa thuật toán).
- Có hướng dẫn chạy và test vector.

**Test vector**
- Key: `HUST2025`
- Plaintext: `Hanoi University of Science and Technology`
- Ciphertext (hex): `BA 0F CE AF E5 E8 85 C2 12 27 31 3A 9A B1 F2 27 F6 75 3C DF 66 96 D4 ED B4 8F 5E 59 5F C0 04 6E 9A DA E7 5A AE D0 65 A8 DB A6`

# LTMM_RC4
