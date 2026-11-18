# AI Documentation

* **Date:** 18 November 2026
* **Project Title:** Student Record And Result Management System in C
* **Author:** Bhumika Verma (SAP ID: 590036739)
* **AI Tool Used:** ChatGPT (OpenAI)

---

## 1. Why I Used AI (Purpose)

I used ChatGPT as a learning assistant to help me refine my C programming project. My main goals were to: 
- Trace and fix annoying buffer bugs during console input.
- Get a second opinion on how to calculate average CGPAs without letting incomplete semesters (marked as `0.0`) break the math.
- Check how to design a simple, offline rule-based advisor system using standard `if-else` blocks instead of complex API integrations.

---

## 2.  Prompts  Sent to the AI

  *1."My C program keeps skipping the student's name input after I enter the SAP ID. How can I clear the input buffer so scanf doesn't skip fields?"*

  *2."I'm writing a CGPA calculation function. Some students have only finished 2 semesters, but the array holds 8 semesters. How can I make sure getCgpa ignores semesters marked as 0.0 so the average doesn't drop?"*
 
  *3."Suggest four different academic categories and advice statements based on CGPA thresholds (like Excellent, Good, etc.) that I can implement natively using a standard C if-else structure."*

  *4."How do I write a basic nested-loop bubble sort to swap whole Student structures in C, both numerically by SAP ID and alphabetically by Name?"*

---

## 3. Useful Insights & Logic I Adopted

 I learned several practical concepts that made the program much more stable:

- Learned that a leading space inside the format string of `scanf(" %99[^\n]", s.name)` is essential. It tells C to skip any trailing newline characters (`\n`) left behind in the buffer from prior numeric inputs.
- Rather than hardcoding a division by `8`, I set up the loop to only increment our semester counter denominator when `sgpa[i] > 0.0f`. This accurately preserves the averages of first- and second-year students.
- Instead of complicating things with pointer arithmetic, I learned that you can swap entire custom `Student` structure variables at once using a simple `temp` structure holder during bubble sort passes.

---

## 4. Academic Advisor Thresholds Design

I worked with the AI to map out a clear, distinct advice matrix. I implemented these ranges natively in my `displayStudent` function:

| CGPA Range | Performance  | Message Advice to Student |
|:---|:---|:---|
| **9.00 to 10.00** | Excellent Performance | *Excellent performance - Maintain your current study pattern!* |
| **7.50 to 8.99** | Good Performance | *Good performance - Try focusing on areas with lower SGPA.* |
| **6.00 to 7.49** | Needs Improvement | *Needs improvement - Dedicate more hours and review core concepts.* |
| **0.01 to 5.99** | Requires Immediate Attention | *Requires immediate attention - Please connect with your advisor.* |

---

## 5. Verification 

I didn't copy-paste the AI suggestions blindly. I modified and hand-coded several features to fit my university project criteria:
1. I deliberately kept the academic advisor offline. It uses predefined boundaries in native C, meaning the program remains lightweight, fast, and does not require active internet connections or external API keys to run.
2. I hand-coded input validation checks inside `add_student_detail` to verify that semesters correspond logically to the selected year (`s.semester <= s.year * 2`), keeping the database mock-data realistic.

---

## 6. Final Project State & Reflections

The collaboration with AI helped me write a much cleaner, error-free console app. The final version successfully manages standard database operations (add, search, display, display all, delete, and sort) and integrates the Offline Academic Advisor cleanly . It was a great exercise in translating high-level guidelines into direct, working C logic .
