---
description: Query and read notes from the user's Obsidian Zettelkasten vault strictly within the obsidian-notes root path
---

# Skill: Obsidian Zettelkasten Query (`obsidian-query`)

## Purpose
Enables the AI agent to search, read, and cross-reference conceptual notes from the user's Obsidian Zettelkasten vault (`/home/yordycg/workspace/personal/obsidian-notes`) when contextualizing study topics.

## Strict Rules & Execution Guardrails
1. **NO UNBOUNDED SEARCHES:** You are strictly **FORBIDDEN** from running `find` or `grep` on `/home/yordycg`, `/home/yordycg/workspace`, or any parent directory. 
2. **STRICT SCOPE:** All search and read operations must be scoped **exclusively** to `/home/yordycg/workspace/personal/obsidian-notes`.
3. **Efficient Commands (Templates):**
   - To find files: `find /home/yordycg/workspace/personal/obsidian-notes -name "*.md"`
   - To search text: `grep -rn "term" /home/yordycg/workspace/personal/obsidian-notes`
