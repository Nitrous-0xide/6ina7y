# 6ina7y
Binary is outdated so i wrote 6ina7y...

6ina7y is a simple new base-2 number system. Binary is too complicated for the [new generation](https://en.wikipedia.org/wiki/Generation_Alpha) and i beleive everyone should get into compsci so i made 6ina7y to help them understand. 

# Usage

```bash
./6ina7y <sequence> [-t | -i]
```
### Options
| Argument | Explaination              |
|----------|---------------------------|
| -t       | Converts result to text   |
| -i       | Converts result to integer|

# Technical details
<sub>(for those who care)</sub>
### Performance Comparison (Integer Mode)

| Bits      | Raw Binary (µs) | 6ina7y Optimized (µs) | Overhead (%) | Notes                     |
|-----------|-----------------|-----------------------|--------------|---------------------------|
| 512       | 0.56            | 0.68                  | +21%         | Very small difference     |
| 4,096     | 4.51            | 4.92                  | +9%          | Excellent                 |
| 32,768    | 41.14           | 46.3                  | +13%         | Good                      |
| 131,072   | 174.74          | 192.8                 | +10%         | Near zero overhead        |

**Summary**: After optimization, **6ina7y** adds only **~0.00015 µs per bit** on average.  
For most real-world sequences, the performance overhead is **negligible**.


<sub>[67 wikipedia article](https://en.wikipedia.org/wiki/6-7)</sub>
